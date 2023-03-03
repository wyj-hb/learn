#include<iostream>
#include<string>
using namespace std;
//练习 3.2:编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词。
//int main()
//{
//	string s;//s是一个空字符串
//	cout << "请输入字符串" << endl;
//	while (getline(cin, s))//一次从给定的输入中读取数据，直到遇到换行符结束，包括空格符也可以被读取
//	{
//		cout << s << endl;
//	}
//	cout << "请输入单词" << endl;
//	//读入一个词
//	char c;
//	while (cin >> c)//遇到文件结束或者不符合数据类型时结束
//	{
//		cout << c << endl;
//	}
//	return 0;
//}
/*练习 3.3:请说明 string 类的输入运算符和 getline 函数分别是如何处理空白字符的*/
//int main()
//{
//	string word, line;
//	cout << "请输入您选择的读取字符串的方式:1.逐词读取2.整行读取" << endl;
//	int i;
//	cin >> i;
//	string s;
//	cin.clear();
//	cin.sync();
//	if (i == 1)
//	{
//		cout << "请输入字符串" << endl;
//		
//		cin >> s;
//		cout << "有效字符串是:" << s << endl;
//		return 0;//程序结束
//	}
//	else if (i == 2)
//	{
//		cin.clear();
//		cin.sync();
//		cout << "请输入字符串" << endl;
//		getline(cin, s);
//		cout << "有效字符串是:" << s << endl;
//		return 0;//程序结束
//	}
//	else
//	{
//		cout << "您的输入有误!" << endl;
//		return 0;
//	}
//}
//练习 3.4:编写一段程序读入两个字符串，比较其是否相等并输出结果。如果不相等，输出较大的那个字符串。改写上述程序，
//比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。
//int main()
//{
	//相等
	/*string l1, l2;
	cout << "请分别输入第一个、第二个字符串,使用空格分割开" << endl;
	cin >> l1>>l2;
	if (l1 == l2)
	{
		cout << "两个字符串大小相等" << endl;
	}
	else if (l1 > l2)
	{
		cout << "字符串l1大" << endl;
	}
	else
	{
		cout << "l2大" << endl;
	}
	return 0;*/
	//等长
//	string l1, l2;
//	cout << "请分别输入第一个、第二个字符串,使用空格分割开" << endl;
//	cin >> l1>>l2;
//	//比较长度
//	auto len1 = l1.size();//使用自动推断类型
//	auto len2 = l2.size();
//	if (len1 == len2)
//	{
//		cout << "两个字符串长度相等" << endl;
//	}
//	else if (len1 > len2)
//	{
//		cout << "字符串l1长" << endl;
//	}
//	else
//	{
//		cout << "l2长" << endl;
//	}
//}
//练习 3.5:编写一段程序从标准输入中读入多个字符串并将它们连接在一起，输出连接成的大字符串。
//然后修改上述程序，用空格把输入的多个字符串分隔开来
int main()
{
	//char ch;
	//string s, result;
	//cout << "请输入第一个字符串" << endl;
	//while (cin >> s)//输入无误
	//{
	//	result += s;//把s拼接到result后面
	//	cout << "是否继续输入  继续:y,不继续:n" << endl;
	//	cin >> ch;
	//	if (ch == 'y')
	//	{
	//		cout << "请输入下一个字符串:" << endl;//继续循环
	//	}
	//	else
	//	{
	//		break;//结束循环
	//	}
	//}
	//cout << "最终的字符串是:" << result << endl;
	//使用空格分隔开
	/*char ch;
	cout << ch <<endl;*/
	//string s, result;
	//cout << "请输入第一个字符串" << endl;
	//while (cin >> s)//输入无误
	//{
	//	if (result.size())
	//	{
	//		//字符串不为空,加上空格
	//		result += " ";
	//		result += s;
	//	}
	//	else
	//	{
	//		result += s;//把s拼接到result后面
	//	}
	//	cout << "是否继续输入  继续:y,不继续:n" << endl;
	//	cin >> ch;
	//	if (ch == 'y')
	//	{
	//		cout << "请输入下一个字符串:" << endl;//继续循环
	//	}
	//	else
	//	{
	//		break;//结束循环
	//	}
	//}
	//cout << "最终的字符串是:" << result << endl;
}