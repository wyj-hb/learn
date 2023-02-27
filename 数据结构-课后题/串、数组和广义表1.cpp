#include<iostream>
using namespace std;
//(3)设二维数组a[1…m, 1…n] 含有m * n 个整数。
//① 写一个算法判断a中所有元素是否互不相同 ? 输出相关信息(yes / no)；
//② 试分析算法的时间复杂度。
//int panduan(int* a[], int m, int n)
//{
//	for (int i = 0;i < m;i++)
//	{
//		for (int j = 0;j < n - 1;j++)
//		{
//			for (int k = j + 1;k < n;k++)//横向对比
//			{
//				if (a[i][j] == a[i][k])
//				{
//					cout << "no" << endl;
//					return 0;//代表no
//				}
//			}
//			for (int d = i + 1;d < m;d++)//从下一行开始
//			{
//				for (int z = 0; z < n;z++)
//				{
//					if (a[i][j] == a[d][z])
//					{
//						cout << "no" << endl;
//						return 0;
//					}
//				}
//			}
//		}
//	}
//	cout << "yes" << endl;
//	return 1;//代表yes
//}
////测试
//int main()
//{
//	int m = 0, n = 0;
//	cout << "请输入二维数组的大小:" << endl;
//	cin >> m;
//	cin >> n;
//	//动态二维数组怎么弄来着？？
//	int** arr = new int* [m];
//	for (int i = 0; i < m; i++)
//		arr[i] = new int[n];
//	cout << "请输入二维数组的值:" << endl;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	panduan(arr, m, n);
//	system("pause");
//	return 0;
//}
//（4）设任意n个整数存放于数组A(1:n)中，试编写算法，将所有正数排在所有负数前面（要求算法复杂度为0(n)）。
//void sort(int a[], int n)
//{
//	int i = 0, j = n - 1, x;  //用类C编写，数组下标从0开始,n-1为最后一个元素的下标
//	while (i < j)
//	{
//		while (i<j && a[i] < 0)  i++;//找到一个符合条件的正数
//		while (i < j && a[j] > 0)  j--;//找到一个符合条件的负数
//		if (i < j && a[i]>0 && a[j] < 0) { x = a[i]; a[i++] = a[j]; a[j--] = x; }//交换A[i] 与A[j]
//	}// while(i<j)
//}
//void display(int a[], int n)
//{
//	for (int i = 0;i < n;i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	int a[5];
//	cout << "请输入数组元素" << endl;
//	for (int i = 0;i < 5;i++)
//	{
//
//		cin >> a[i];
//	}
//	sort(a, 5);
//	display(a, 5);
//	system("pause");
//	return 0;
//}
//（5）已知字符串S1中存放一段英文，写出算法format(s1, s2, s3, n), 将其按给定的长度n格式化成两端对齐的字符串S2, 其多余的字符送S3。
//格式化字符串:即长度为n且首尾字符不得为空格字符。
//void format(char* s1, char* s2, char* s3, int n)
//{
//	char* p = s1;
//	char* q = s2;
//	while (*p == ' '&& *p != '\0') { p++; };//保证复制到s2字符串首位置不是空格
//	if (*p == '\0')
//	{
//		cout << "抱歉,您输入的字符串错误" << endl;
//	}
//	int i = 0;
//	while (*p != '\0' && i < n)
//	{
//		*q = *p;
//		p++;
//		q++;
//		i++;
//	}
//	if (*p == '\0')
//	{
//		cout << "s1串没有" << n << "个两端对齐的字符串" << endl; exit(0);
//	}
//	//判断最后一个字符是否是空格
//	if (*(--q) == ' ') //若最后一个字符为空格，则需向后找到第一个非空格字符
//	{
//		p--;          //p指针也后退
//		while (*p == ' ' && *p != '\0') p++;//往后查找一个非空格字符作串s2的尾字符
//		if (*p == '\0')
//		{
//			cout << "s1串没有" << n << "个两端对齐的字符串" << endl; exit(0);
//		}
//		*q = *p;         //字符串s2最后一个非空字符
//		*(++q) = '\0';   //置s2字符串结束标记
//	}
//	//将剩余子串复制给s3
//	q = s3;
//	p++;      //将s1串其余部分送字符串s3。
//	while (*p != '\0') { *q = *p; q++; p++; }
//	*q = '\0';        //置串s3结束标记
//}
//（6）编写算法，实现下面函数的功能。函数void insert(chars, chart, int pos)将字符串t插入到字符串s中，插入位置为pos。假设分配给字符串s的空间足够让字符串t插入。（说明：不得使用任何库函数）
//void insert(char* s, char* t, int pos)
//{
//	int a = 0;
//	int i = 1, x = 0;//i表示数组中的第几个元素,i = 1 是表示的是s[0];
//	char* p = s, * q = t;//p，q分别为字符串s和t的工作指针
//	if (pos < 1)
//	{
//		cout << "pos参数位置非法" << endl;
//		exit(0);
//	}
//	while (*p != '\0' && i < pos)
//	{
//		i++;
//	}//查pos位置
//	 //若pos小于串s长度，则查到pos位置时，i=pos。
//	if (*p == '\0')//此时说明字符串到头，长度不足
//	{
//		cout << pos << "大于字符串长度" << endl;
//		exit(0);
//	}
//	else
//	{
//		//此时说明位置无误,找出插入后的字符串的'/0'的位置
//		while (*p != '\0')
//		{
//			p++;
//			i++;
//		}
//	}
//	//此时p指向'/0'处,i代表的下标元素也是'/0'
//	a = i;//包含着'/0'的长度
//	while (*q != '\0') { q++; x++; }   //查找字符串t的长度x，循环结束时q指向'\0'。
//	int m = a + x;//总长度
//	for (int j = i; j >= pos; j--)//将pos位置元素后的元素集体向右移x个位置
//	{
//		*(p + x) = *p;
//		p--;
//	}
//	q--;  //指针q回退到串t的最后一个字符,不去复制'/0'
//	for (int j = 1; j <= x; j++) *p-- = *q--;  //将t串的x个字符插入到s的pos位置上
//}