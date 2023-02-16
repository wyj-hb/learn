#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef string elemType;
class Stack//抽象基类
{
public:
	virtual ~Stack() {};
	virtual bool pop(elemType&) = 0;//出栈函数
	virtual bool push(const elemType&) = 0;//入栈函数
	virtual bool peek(int index, elemType&) = 0;
	virtual int top() const = 0;
	virtual int size() const = 0;
	virtual bool empty() const = 0;//判断是否为空
	virtual bool full() const = 0;//判断是否已满
	virtual void print(ostream & = cout)const = 0;
};
ostream& operator<<(ostream& os, const Stack& rhs)//重载=运算符
{
	rhs.print();
	return os;
}
class LIFO_Stack : public Stack//派生类
{
public:
	LIFO_Stack(int capacity = 0) : _top(0)
	{
		if (capacity)//传入的容器大小不为0
		{
			_stack.reserve(capacity);//预留空间
		}
	}
	int size() const
	{
		return _stack.size();
	}
	bool empty() const
	{
		return !_top;
	}
	bool full() const
	{
		return size() > _stack.max_size();
	}
	int top() const { return _top; };
	void print(ostream& os = cout) const;
	bool pop(elemType&);//出栈函数
	bool push(const elemType&);//入栈函数
	bool peek(int index, elemType&);

private:
	vector<elemType> _stack;//存放元素的容器
	int _top;//top指针
};
//函数实现
//出栈
bool LIFO_Stack::pop(elemType& elem)
{
	//判断是否为空
	if (empty())
	{
		return false;
	}
	elem = _stack[--_top];
	_stack.pop_back();//；令此时的top所指向的位置元素为空；
	return true;
}
//入栈
bool LIFO_Stack::push(const elemType& elem)
{
	//判断是否已满
	if (full())
	{
		return false;
	}
	_stack.push_back(elem);
	++_top;
	return true;
}
//输出函数
void LIFO_Stack::print(ostream& os)const//参数默认值已于先前指定过，此处不应重复指定
{
	vector<elemType>::const_reverse_iterator rit = _stack.rbegin(), rend = _stack.rend();//该迭代器可以以逆向方式由尾端至前端遍历整个vector
	os << "\n\t";
	while (rit != rend)
	{
		os << *rit++ << "\n\t";
	}
	os << endl;
}
bool LIFO_Stack::peek(int index, elemType& elem)//输入index的值，如果该位置存在，则返回该位置上的值
{
	if (empty())
	{
		return false;
	}
	if (index < 0 || index >= size())
	{
		return false;
	}
	elem = _stack[index];
	return true;
}
void peek(Stack& st, int index)
{
	cout << endl;
	string t;
	if (st.peek(index, t))
	{
		cout << "peek: " << t;
	}
	else
	{
		cout << "peek failed";
	}
	cout << endl;
}
int main()
{
	LIFO_Stack st;
	LIFO_Stack s;
	string str;
	while (cin >> str && !st.full())//输入str以空格分隔
	{
		st.push(str);
		cout << '\n' << "About to call peek() with LIFO_Stack" << endl;
		//peek(st, st.top() - 1);
		cout << st;//输出栈顶值
		
		while (!st.empty())
		{
			string t;
			if (st.pop(t))
			{
				s.push(t);
				
			}
		}
	}
	cout << "About to call peek() with Peekback_Stack" << endl;
	peek(s,s.top() - 1);
	cout << s;
}