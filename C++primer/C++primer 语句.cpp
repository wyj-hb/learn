#include<iostream>
using namespace std;
//练习 5.9:编写一段程序，使用一系列 if 语句统计从 cin 读入的文本中有多少元音母。
//int main()
//{
//	char ch;
//	unsigned int v = 0;
//	cout << "请输入一个字母" << endl;
//	while (cin >> ch)
//	{
//		if (ch == 'a')
//		{
//			++v;
//		}
//		if (ch == 'e')
//		{
//			++v;
//		}
//		if (ch == 'i')
//		{
//			++v;
//		}
//		if (ch == 'o')
//		{
//			++v;
//		}
//		if (ch == 'u')
//		{
//			++v;
//		}
//	}
//	cout << "您输入的文本中共有:" << v << "个元音字母" << endl;
//	return 0;
//}
//练习 5.10 : 我们之前实现的统计元音字母的程序存在一个问题 : 如果元音字母以大写形式出现，不会被统计在内。编写一段程序，既统计元音字母的小写形式，
// 也统计大写形式，也就是说，新程序遇到'a'和'A'都应该递增 aCnt 的值，以此类推。
//int main()
//{
//	char ch;
//	unsigned int v = 0;
//	cout << "请输入一个字母" << endl;
//	while (cin >> ch)
//	{
//		if (ch == 'a' || ch == 'A')
//		{
//			++v;
//		}
//		if (ch == 'e' || ch == 'E')
//		{
//			++v;
//		}
//		if (ch == 'i' || ch == 'I')
//		{
//			++v;
//		}
//		if (ch == 'o' || ch == 'O')
//		{
//			++v;
//		}
//		if (ch == 'u' || ch == 'U')
//		{
//			++v;
//		}
//	}
//	cout << "您输入的文本中共有:" << v << "个元音字母" << endl;
//	return 0;
//}
//练习 5.11 : 修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。
//int main()
//{
//	//初始化各个要统计的量
//	unsigned int  a = 0, e = 0, i = 0, o = 0, u = 0;
//	unsigned int space = 0, tab = 0, enter = 0;
//	char ch;
//	while (cin.get(ch))
//	{
//		switch (ch)
//		{
//		case 'a':
//		case 'A':
//			a++;
//			break;
//		case 'e':
//		case 'E':
//			e++;
//			break;
//		case 'I':
//		case 'i':
//			i++;
//			break;
//		case 'o':
//		case 'O':
//			o++;
//			break;
//		case 'u':
//		case 'U':
//			u++;
//			break;
//		case ' ':
//			space++;
//			break;
//		case '\n':
//			enter++;
//			break;
//		case '\t':
//			tab++;
//			break;
//		}
//	}
//	cout << "a数量为" << a << endl;
//	cout << "e数量为" << e << endl;
//	cout << "i数量为" << i << endl;
//	cout << "o数量为" << o << endl;
//	cout << "u数量为" << u << endl;
//	cout << "空格数量为" << space << endl;
//	cout << "制表符数量为" << tab << endl;
//	cout << "回车数量为" << enter << endl;
//	return 0;
//}
//练习 5.12 : 修改统计元音字母的程序, 使其能统计以下含有两个字符的字符序列的数量 : ff、fl 和 fi。
//int main()
//{
//	unsigned int ff = 0, fl = 0, fi = 0;
//	string s1;
//	char ch;
//	char s = ' ';
//	cout << "请输入一段文本:" << endl;
//	while (cin >> ch)
//	{
//		bool y = true;
//		if (s == 'f')
//		{
//			switch (ch)
//			{
//			case 'f':
//				y = false;
//				ff++;
//				break;
//			case 'l':
//				fl++;
//				break;
//			case 'i':
//				fi++;
//				break;
//			}
//		}
//		if (!y)
//		{
//			s = ' ';
//		}
//		else
//		{
//			s = ch;
//		}
//	}
//	cout << "f1有" << fl << "个" << endl;
//	cout << "ff有" << ff << "个" << endl;
//	cout << "fi有" << fi << "个" << endl;
//}