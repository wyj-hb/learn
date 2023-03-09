#include<iostream>
#include<vector>
using namespace std;
//5.4.1 节练习
//练习 5.14:编写一段程序，从标准输入中面读取若干 string 对象并查找连续重复出现的单词。所谓连续重复出现的意思是 : 一个单词后面紧跟着这个单词本身。
//要求记录连续重复出现的最大次数以及对应的单词。如果果这样的单词存在, 输出重复出现的最大次数如果不存在，输出一条信息说明任何单词都没有连续出现过。
//例如，如果输入是how now now now brown cow cow那么输出应该表明单词 now 连续出现了3 次。
//int main()
//{
//	string s1,s2;//s1为当前串，s2为s1的前一个字符串
//	string s3;//使用s3来记录当前保存的最大连续字符串
//	int max = 0, current = 1;//max是当前记录的已知的最大连续相同的字符串,current是当前连续的字符串的数量
//	cout << "请输入字符串" << endl;
//	while (cin >> s1)
//	{
//		if (s1 == s2)
//		{
//			++current;//当前已知连续出现的字符串的数量
//			if (current > max)
//			{
//				max = current;
//				s3 = s1;
//			}
//		}
//		else//不是重复的
//		{
//			current = 1;
//			s2 = s1;
//		}
//	}
//	if (max > 1)
//	{
//		//此时说明存在连续字符串
//		cout << "连续字符串是" << s3 << ",最大连续长度为" << max << endl;
//	}
//	else
//	{
//		cout << "并未出现连续字符串" << endl;
//	}
//}
//练习 5.17:假设有两个包含整数的 vector 对象, 编写一段程序, 检验其中一个 vector对象是否是另一个的前缀。为了实现这一目标，
// 对于两个不等长的 vector 对象，只需挑出长度较短的那个，把它的所有元素和另一个vector 对象比较即可。例如，如果两个 vector 
//对象的元素分别是 0、1、1、2 和0、1、1、2、3、5、8，则程序的返回结果应该为真。
//找出三个数中的最大值
//bool pandaun(vector<int> v1,vector<int> v2)
//{
//	auto i1 = v1.begin();
//	auto i2 = v2.begin();
//	int x = 0;
//	while (i1 != v1.end() && i2 != v2.end())//比较没有到头
//	{
//		if (*i1 != *i2)
//		{
//			break;
//		}
//		else
//		{
//			x++;
//			i1++;
//			i2++;
//		}
//	}
//	if (x)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//int main()
//{
//	//初始化容器
//	vector<int> v1 = { 1,2,3,4,5,3,0,1,0 };
//	vector<int> v2 = { 1,2,3,4,6,8,3 };
//	vector<int> v3 = { 0,2,2,5,62,23 };
//	//进行判断操作
//	bool x = pandaun(v1, v3);
//	if (x)
//	{
//		cout << "是他的前缀" << endl;
//	}
//	else
//	{
//		cout << "不是它的前缀" << endl;
//	}
//}
//练习 5.19:编写一段程序，使用 do-while循环重复地执行下述任务 : 首先提示用户
//输入两个 string 对象，然后挑出较短的那个并输出它。
//int main()
//{
//	cout << "请输入两个string对象" << endl;
//	string s1, s2;
//	cin >> s1 >> s2;
//	if (s1.size() > s2.size())
//	{
//		cout << s2 << endl;
//	}
//	else if (s1.size() < s2.size())
//	{
//		cout << s1 << endl;
//	}
//	else
//	{
//		cout << "两个一样长" << endl;
//	}
//	return 0;
//}
//5.5.1 节练习
//练习 5.20:编写一段程序，从标准输入中中读取 string 对象的序列直到连续出现两个相同的单词或者所有单词都读完为止。使用 while 循环一次读取一个单词，
//当一个单词连续出现两次时使用 break 语句终止盾环。输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。
//int main()
//{
//	string s1,s2;//s2为s1的前面的字符串
//	bool x = false;//用于判断是否有连续两次的单词出现
//	while (cin >> s1)
//	{
//		if (s1 == s2)
//		{
//			x = true;
//			break;
//		}
//		else
//		{
//			s2 = s1;
//		}
//	}
//	if (x)
//	{
//		cout << "有重复的,重复的是:" << s1;
//	}
//	else
//	{
//		cout << "没有重复的出现" << endl;
//	}
//	return 0;
//}
//5.5.3 节练习
//练习 5.22:本节的最后一个例子跳回到 begin，其实使用循环能更好地完成该任务。
//重写这段代码，注意不再使用 goto 语句
//int main()
//{
//	int sz;
//	do
//	{
//		sz = get_size();
//	} while (sz <= );
//}
//5.6.3 节练习
//练习 5.23:编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。
//int main()
//{
//	int x1,x2;
//	cout << "请输入两个整数" << endl;
//	cin >> x1 >> x2;
//	cout << x1 / x2 << endl;
//}
//练习 5.24 : 修改你的程序，使得当第二个数是0时抛出异常。先不要设定 catch 子句，运行程序并真的为除数输入 0，看看会发生什么 ?
//int main()
//{
//	int x1, x2;
//	cout << "请输入两个整数" << endl;
//	cin >> x1 >> x2;
//	if (x2 == 0)
//	{
//		throw runtime_error("除数不能为0");//抛出异常
//	}
//	cout <<"结果为:"<< x1 / x2 << endl;
//}
//练习 5.25 : 修改上一题的程序，使用t ry 语句块去捕获异常。catch 子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行 try语句块的内容。
//int main()
//{
//	int x1, x2;
//	cout << "请输入两个整数" << endl;
//	while (cin >> x1 >> x2)
//	{
//		try
//		{
//			if (x2 == 0)
//			{
//				throw runtime_error("除数不能为0");
//			}
//			cout << "两数相除结果是:" << x1 / x2 << endl;
//		}
//		catch(runtime_error err)
//		{
//			cout << err.what() << endl;//打印输出错误信息
//			cout << "还需要继续吗?(y or n)" << endl;
//			char ch;
//			cin >> ch;
//			if (ch == 'n' || ch == 'N')
//			{
//				break;
//			}
//		}
//	}
//}
//练习 6.3:编写你自己的 fact 函数，上机检查是否正确。
//int fact(int val)
//{
//	if (val < 0)
//	{
//		//此时不满足要求
//		return -1;
//	}
//	int ret = 1;
//	for (int i = 1;i != val + 1;i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//int main()
//{
//	int x = fact(5);
//	cout << x << endl;
//}
//练习 6.7:编写一个函数，当它第一次被调用时返回 0，以后每次被调用返回值加1。
//int fanhui(int &x)
//{
//	x++;
//	return x;
//}
//int main()
//{
//	int x = 0;
//	fanhui(x);
//	cout << x << endl;
//	fanhui(x);
//	cout << x << endl;
//	fanhui(x);
//	cout << x << endl;
//}