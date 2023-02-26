#include<iostream>
#include<string>
using namespace std;
//(1)已知模式串 t = "abcaabbabcab", 写出用KMP法求得的每个字符对应的 next 和 nextval
//函数值
//void get_next(t T, int& next[])//next数组从1开始
//{
//	int i = 1;int j = 0;//j用来记录下次返回应该回到的位置
//	next[1] = 0;//所求的next数组
//	while (i < T.length)//索引位置不超过数组T的长度
//	{
//		if (t[i] == t[j] && j == 0)
//		{
//			i++;
//			j++;
//			next[i] = j;
//		}
//		else
//		{
//			//不满足条件
//			j = next[j];//该位置不符合匹配条件，从该位置对应的next数组位置返回
//		}
//	}
//}
//void get_nextval(t T, int& nextval[])
//{
//	int i = 1;
//	int j = 0;
//	nextval[1] = 0;//next[0]不存储，与i相对应
//	while (i < T.length)
//	{
//		if (t[i] == t[j] && j == 0)
//		{
//			i++;j++;
//			next[i] == j;
//			if (t[i] != t[j])//条件判断
//			{
//				//与原来相同
//				nextval[i] == j;
//			}
//			else
//			{
//				nextval[i] == nextval[j];
//			}
//		}
//	}
//}
//(2)写一个算法统计在输入字符串中各个不同字符出现的频度并将结果存入文件（字符串中
//的合法字符为 A~Z 这 26 个字母和 0~9 这 10 个数字）。
//#define Maxsize 1000
//void Count()//统计输入字符串中数字字符和字母字符的个数。
//{
//	string s;
//	cin >> s;
//	int num[Maxsize];
//	for (int i = 0; i < 36; i++)
//		num[i] = 0;// 初始化
//	for (int i = 0;;i++)
//	{
//		if (s[i] == '#')
//		{
//			break;
//		}
//		else
//		{
//			if ('0' <= s[i] <= '9')  //数字字符
//			{
//				int x = s[i] - 48;//ch此时为数字的ascll码,相减得出i的值
//				num[x]++;
//			}
//			else if ('A' <= s[i] <= 'Z')  //字母字符
//			{
//				int x = s[i] - 'A' + 10;//防止重复
//				num[x]++;
//			}
//		}
//	}
//	//int num[36];//初始化数组
//	//char ch;
//	
//	//while ((ch = getchar()) != '#')
//	//{
//	//	if ('0' <= ch <= '9')  //数字字符
//	//	{
//	//		int i = ch - 48;//ch此时为数字的ascll码,相减得出i的值
//	//		num[i]++;
//	//	}
//	//	else if ('A' <= ch <= 'Z')  //字母字符
//	//	{
//	//		int i = ch - 'A' + 10;//防止重复
//	//		num[i]++;
//	//	}
//	//}//循环，最后以接收到#字符结束
//	for (int i = 0; i < 10; i++)
//	{
//		if (num[i])
//		{
//			cout << "数字" << i << "的个数=" << num[i] << endl;
//		}
//		
//	}
//	for (int i = 10; i < 36; i++)
//	{
//		if (num[i])
//		{
//			cout << "字母字符" << i + 55 << "的个数=" << num[i] << endl;
//		}
//	}
//}
//int main()
//{
//	Count();
//	system("pause");
//	return 0;
//}
//（3）写一个递归算法来实现字符串逆序存储，要求不另设串存储空间。
//本题要求通实现将字符串逆序存储的操作并且不另设串存储空间，即第一个输入的字符最后一个存储
//int InvertStore(char A[])
////字符串逆序存储的递归算法。
//{
//	char ch;
//	static int i = 0;//需要使用静态变量，保证i的值可以被我们记录下来
//	cin >> ch;//输入一个字符
//	if (ch != '.')    //规定'.'是字符串输入结束标志
//	{
//		InvertStore(A);//递归调用自己
//		A[i++] = ch;//找到最后一个字符返回上一级，并存储到A数组中
//	}
//	A[i] = '\0';  //字符串结尾标记
//
//	return i;
//}
//void display(char A[], int i)
//{
//	for (int k = 0; k < i; k++)
//	{
//		cout << A[k] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	char A[100];
//	int i = InvertStore(A);
//	display(A, i);
//	system("pause");
//	return 0;
//}
//
//
