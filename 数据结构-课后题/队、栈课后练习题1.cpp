#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
//(1)将编号为 0 和 1 的两个栈存放于一个数组空间 V[m]中，栈底分别处千数组的两端。当第
//0 号栈的栈顶指针 top[O]等于 - 1 时该栈为空；当第 1 号栈的栈顶指针 top[l]等千 m 时，该栈为空。
//两个栈均从两端向中间增长（见图 3.17)。试编写双栈初始化，判断栈空、栈满、进栈和出栈等算
//法的函数。
//typedef struct
//{
//	int top[2], bot[2];//初始化栈顶指针和栈低指针
//	int* v;//数组，存放数据
//	int m;//存放的最大值
//
//}Snode, * LinkSnode;
////判断栈空
//bool pandaun(LinkSnode& L)
//{
//	if (L->top[0] == -1 && L->top[1] == m)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
////判断栈满
//bool zhanman(LinkSnode& L)
//{
//	if (L->top[1] - L->top[0] == 1 || L->top[0] > L->m - 1 || L->top[1] < 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
////进栈
//int jinzhan(LinkSnode L, int e, int i)//e为进栈的数据
//{
//	//首先判断是否栈满
//	if (zhanman(L))
//	{
//		cout << "该栈已满，无法进行入栈" << endl;
//		return 0;
//	}
//	else
//	{
//		if (i == 0)
//		{
//			//进入栈1
//			L->top[0]++;
//			L->v[L->top[0]] = e;
//			return 0;
//		}
//		else if (i == 1)
//		{
//			L->v[L->top[1]] = e;
//			L->top[1]--;
//			return 0;
//		}
//		else
//		{
//			cout << "您输入的数据有误" << endl;
//		}
//	}
//}
////出栈
//int chuzhan(LinkSnode &L, int &e, int i)//e为进栈的数据
//{
//	if (i < 0 || i>1)
//	{
//		cout << "输入有误" << endl;
//
//	}
//	switch (i)
//	{
//	case 0:
//		if (L->top[0] == -1)
//		{
//			return 0;
//		}
//		else
//		{
//			e = L->v[L->top[0]];
//			L->top[0]--;
//			return 0;
//		}
//	case 1:
//		if (L->top[1] == L->m)
//		{
//			return 0;
//		}
//		else
//		{
//			L->top[1]++;
//			e = L->v[L->top[1]];
//			return 0;
//		}
//	}
//}
//（2）回文是指正读反读均相同的字符序列，如“abba”和“abdba”均是回文，但“good”不是回文。试写一个算法判定给定的字符向量是否为回文。
//根据提示，算法可设计为：
//typedef char DataType;
//#define maxsize 1000
//typedef struct {
//	DataType* top;
//	DataType* bottom;
//	int size;
//}SeqStack;
//void InitStack(SeqStack& s)
//{
//	s.top = new DataType(maxsize);
//	if (!s.top)
//	{
//		exit(OVERFLOW);
//	}
//	s.top = s.bottom;
//	s.size = maxsize;
//	return;
//}
//bool push(SeqStack& s, char e)
//{
//	//判断是否已满
//	if (s.top - s.bottom == s.size)
//	{
//		return false;
//	}
//	else
//	{
//		*s.top++ = e;
//		return true;
//	}
//}
//char pop(SeqStack& s)
//{
//	//判断是否为空
//	if (s.top == s.bottom)
//	{
//		return 0;
//	}
//	else
//	{
//		return *--s.top;
//	}
//}
//int IsHuiwen(string t)
//{//判断t字符向量是否为回文，若是，返回1，否则返回0
//	SeqStack s;
//	int i, len;
//	//入栈
//	for (int i = 0;i < len / 2;i++)
//	{
//		push(s, t[i]);
//		if (!push(s,t[i]))
//		{
//			break;
//		}
//	}
//	//出栈并判断
//	if (len % 2 == 0)
//	{
//		for (int i = len / 2;i < len;i++)
//		{
//			char e = pop(s);
//			if (t[i] = e)
//			{
//				continue;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		return 1;
//	}
//	if (len % 2 == 1)
//	{
//		for (int i = len / 2 + 1;i < len;i++)
//		{
//			char e = pop(s);
//			if (t[i] = e)
//			{
//				continue;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		return 1;
//	}
//}
//(3) 设从键盘输入一整数的序列：a, , a2, a瓦.., an, 试编写算法实现：用栈结构存储输入的整
//数， 当 ad - I 时，将 a;进栈；当 a; = -1 时，输出栈顶整数并出栈。算法应对异常情况（入栈满
//等） 给出相应的信息。
//#define maxsize 1000
//void InOutS(int s[maxsize],int n)
////s是元素为整数的栈，本算法进行入栈和退栈操作。
//{
//    int top = 0;             //top为栈顶指针，定义top=0时为栈空。
//    for (int i = 1; i <= n; i++)    //n个整数序列作处理。
//    {
//        cout << "请输入一个整数" << endl;
//        int x = 0;
//        cin >> x;//从键盘读入整数序列。
//        if (x != -1)           // 读入的整数不等于-1时入栈。
//            if (top == maxsize) { cout << "栈满" << endl;exit(0); }
//            else s[top++] = x; //x入栈。
//        else   //读入的整数等于-1时退栈。
//        {
//            if (top == 0) { cout << "栈空" << endl;exit(0); }
//            else cout << "出栈元素为：" << s[--top] << endl;
//        }
//    }
//}//算法结束。
//(4)从键盘上输入一个后缀表达式，试编写算法计算表达式的值。规定：逆波兰表达式的长
//度不超过一行，以 "$"作为输入结束，操作数之间用空格分隔，操作符只可能有＋、—、＊、／四种
//运算。例如： 23434 + 2 * $。
//typedef struct Snode{
//	struct Snode* next;
//	int data;
//}Snode,*LinkSnode;
//void init(LinkSnode& L)
//{
//	L = new Snode;
//	return;
//}
//void push(Snode* &L, int e)
//{
//	Snode* s = new Snode;
//	s->data = e;
//	L = s->next;
//	L = s;
//}
//void pop(LinkSnode& L,int &e)
//{
//	if (L == NULL)
//	{
//		cout << "抱歉栈空无法出栈" << endl;
//	}
//	e = L->data;
//	LinkSnode s = L;
//	L = L->next;
//	delete s;
//}
//int in(char c)
//{
//	if (c == '+' || c == '-' || c == '*' || c == '/')
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int operate(int a, char b, int c)
//{
//	switch (b)
//	{
//	case '+':
//		return a + c;
//	case '-':
//		return a - c;
//	case '*':
//		return a * c;
//	case '/':
//		return a / c;
//	}
//	return 0;
//}
//int gettop(LinkSnode& L)
//{
//	//判断是否为空
//	if (L == NULL)
//	{
//		return 0;
//	}
//	return L->data;
//}
//int bolan()
//{
//	char ch;
//	LinkSnode L;
//	init(L);
//	while(true)
//	{
//		cin >> ch;
//		if (ch != '!')
//		{
//			if (in(ch))//是操作符
//			{
//				int a, c;
//				pop(L, a);
//				pop(L, c);
//				push(L, operate(a, ch, c));
//			}
//			else//是操作数
//			{
//				push(L, stoi((const char*)ch));
//			}
//		}
//		else
//		{
//			break;
//		}
//	}
//	//最终出栈顶
//	int x = gettop(L);
//	return x;
//}
//int main()
//{
//	int z = bolan();
//	cout << z << endl;
//	system("cls");
//	system("pause");
//	return 0;
//}
//（5）假设以I和O分别表示入栈和出栈操作。栈的初态和终态均为空，入栈和出栈的操作序列可表示为仅由I和O组成的序列，称可以操作的序列为合法序列，否则称为非法序列。
//①下面所示的序列中哪些是合法的？
//A.IOIIOIOO     B.IOOIOIIO      C.IIIOIOIO     D.IIIOOIOO
//②通过对①的分析，写出一个算法，判定所给的操作序列是否合法。若合法，返回true，否则返回false（假定被判定的操作序列已存入一维数组中）。
//#define Maxsize 100
//typedef struct Snode
//{
//	char data[Maxsize];
//	int top;
//}Snode,*LinkSnode;
//void init(Snode& L)
//{
//	L.top = -1;
//}
//void push(Snode& L, string x)
//{
//	//判断是否已满
//	if (L.top == Maxsize - 1)
//	{
//		cout << "栈已满，无法入栈";
//		return;
//	}
//	else
//	{
//		for (int i = 0;;i++)
//		{
//			if ((const char*)x[i] != "a")
//			{
//				L.data[++L.top] = x[i];
//			}
//			else
//			{
//				return;
//			}
//		}
//		
//	}
//}
//int judge(Snode &S)
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	while (S.data[i]!='a')
//	{
//		switch (S.data[i])
//		{
//		case 'I':
//			j++;
//			break;
//		case '0':
//			k++;
//			break;
//		}
//		if (k > j)
//		{
//			return 0;
//			break;
//		}
//		i++;
//	}
//	if (k != j)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//int main()
//{
//	Snode S;
//	init(S);
//	string s;
//	cout <<"请输入:" << endl;
//	cin >> s;
//	push(S, s);
//	if (judge(S))
//	{
//		cout << "合法" << endl;
//	}
//	else
//	{
//		cout << "不合法" << endl;
//	}
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#define  MaxSize 100
typedef char ElemType;
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;
enum Status { ERROR, OK };

//初始化栈
Status InitStack(SqStack& s)
{
	s.top = -1;
	return OK;
}
//入栈
void push(SqStack& L, string x)
{
	//判断是否已满
	if (L.top == MaxSize - 1)
	{
		cout << "栈已满，无法入栈";
		return;
	}
	else
	{
		for (int i = 0;;i++)
		{
			if ((char)x[i] != 'b')
			{
				L.data[++L.top] = x[i];
			}
			else
			{
				return;
			}
		}

	}
}
//判断合法性
int JudgeLegal(SqStack& s)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (s.data[i] != 'a')
	{
		switch (s.data[i])
		{
		case 'I':j++;break;
		case '0':k++;break;
		}
	/*	if (k > j)
		{
			return 1;
		}*/
		i++;
	}
	cout << k << endl;
	cout << j << endl;
	if (j == k)
	{
		return 0;
	}
	else
	{
		return 100;
	}
}
int main(int argc, char* argv[])
{
	SqStack S;
	InitStack(S);
	string s(500,0);
	cout <<"请输入:" << endl;
	cin >> s;
	push(S,s);
	if (JudgeLegal(S))
	{
		printf("序列不合法\n");
	}
	else
	{
		printf("序列合法!\n");
	}

	return 0;
}
