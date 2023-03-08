#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;
//练习 3.35:编写一段程序，利用指针将数组中的元元素置为 0。
//int main()
//{
//	const int sz = 10;
//	int arr[10];
//	for (int i = 0;i < 10;i++)//初始化数组
//	{
//		arr[i] = i;
//	}
//	cout << "初始化数组的内容是:" << endl;
//	for (auto i : arr)
//	{
//		cout << i << endl;
//	}
//	cout << "改变后:" << endl;
//	int* p = arr;
//	for (int i = 0;i < 10;i++)
//	{
//		*(p + i) = 0;
//	}
//	for (auto i : arr)
//	{
//		cout << i << endl;
//	}
//	return 0;
//}
//练习 3.36 : 编写一段程序，比较两个数组是否相等等。再写一段程序，比较两个 vector对象是否相等。
//int main()
//{
	//判断两个数组是否相等
	//初始化
	//const int sz = 5;
	//int arr1[sz], arr2[sz];
	//srand((unsigned)time(NULL));//生成随机数种子
	//for (int i = 0;i < 5;i++)
	//{
	//	arr1[i] = rand() % 5;//每次随机生成5以内的数
	//}
	//cout << "随机数已经生成完毕，请输入您要猜的数字(5个):" << endl;
	//int val;
	//int x = 0;
	//while (cin >> val)
	//{
	//	if (x == 5)
	//	{
	//		cout << "输入完毕" << endl;
	//		break;
	//	}
	//	arr2[x] = val;
	//	x++;
	//}
	//cout << "系统产生为:" << endl;
	//for (auto i : arr1)
	//{
	//	cout << i << endl;
	//}
	//cout << "自行输入的为:" << endl;
	//for (auto i : arr2)
	//{
	//	cout << i << endl;
	//}
	////判断是否相等
	//auto a = begin(arr1);
	//auto b = begin(arr2);
	//bool panduan = true;
	//for (int i = 0;i<5;i++)
	//{
	//	if (*(arr1 + i) != *(arr2 + i))
	//	{
	//		cout << "不相等" << endl;
	//		panduan = false;
	//		break;
	//	}
	//}
	//if (panduan)
	//{
	//	cout << "相等" <<endl;
	//}
	//return 0;
    //判断两个vector容器
//	const int sz = 5;
//	vector<int> v1, v2;
//	srand((unsigned)time(NULL));//生成随机数种子
//	for (int i = 0;i < 5;i++)
//	{
//		v1.push_back((rand() % 5));//每次随机生成5以内的数
//	}
//	cout << "随机数已经生成完毕，请输入您要猜的数字(5个):" << endl;
//	int val;
//	int x = 0;
//	while (cin >> val)
//	{
//		if (x == 5)
//		{
//			cout << "输入完毕" << endl;
//			break;
//		}
//		v2.push_back(val);
//		x++;
//	}
//	cout << "系统产生为:" << endl;
//	for (auto i : v1)
//	{
//		cout << i << endl;
//	}
//	cout << "自行输入的为:" << endl;
//	for (auto i : v2)
//	{
//		cout << i << endl;
//	}
//	//判断是否相等
//	auto it1 = v1.begin();
//	auto it2 = v2.begin();
//	bool panduan = true;
//	for (int i = 0;i<5;i++)
//	{
//		if (*(it1 + i) != *(it2 + i))
//		{
//			cout << "不相等" << endl;
//			panduan = false;
//			break;
//		}
//	}
//	if (panduan)
//	{
//		cout << "相等" <<endl;
//	}
//	return 0;
//}
//练习 3.39:编写一段程序，比较两个 string 对象。再编写一段程序，比较两个C风格字符串的内容。
//int main()
//{
	//比较两个string对象
	/*string s1, s2;
	cout << "请分别输入两个string对象,以空格区分开:" << endl;
	cin >> s1 >> s2;
	cout << "比较信息如下:" << endl;
	if (s1 > s2)
	{
		cout << "第一个字符串更大" << endl;
	}
	else if (s1 < s2)
	{
		cout << "第二个字符串更大" << endl;
	}
	else
	{
		cout << "两个字符串一样大" << endl;
	}*/
	//比较两个C风格字符串
//	const int se = 10;
//	char arr1[se], arr2[se];
//	cout << "请分别输入两个字符串,以空格区分开:" << endl;
//	cin >> arr1 >> arr2;
//	auto i = strcmp(arr1, arr2);
//	//比较
//	cout << "比较信息如下:" << endl;
//	switch (i)
//	{
//	case 1:
//		cout << "第一个字符串大" << endl;
//		break;
//	case -1:
//		cout << "第二个字符串大" << endl;
//		break;
//	case 0:
//		cout << "一样大" << endl;
//		break;
//	default:
//		cout << "未经定义的结果" << endl;
//		break;
//	}
//	return 0;
//	
//}
//练习 3.40 : 编写一段程序，定义两个字符数组并用字符串字面值初始化它们;接着再定义一个字符数组存放前两个数组连接后的结果。使用 strcpy 和 strcat 把前两个数组的内容拷贝到第三个数组中。
//#define Maxsize 1000
//int main()
//{
//	char str1[] = "hello";
//	char str2[] = "world";
//	char str3[Maxsize];
//	strcpy_s(str3, str1);
//	strcat_s(str3, str2);
//	cout << "拼接后" << endl;
//	cout << str3 << endl;
//}
//练习 3.41:编写一段程序，用整型数组初始化一个 vector 对象。
//int main()
//{
//	const int sz = 10;
//	int a[sz];
//	srand((unsigned)time(NULL));
//	cout << "数组的内容是:" << endl;
//	for (auto& val : a)//数组的范围是0-100
//	{
//		val = rand() % 100;
//		cout << val<<" ";
//	}
//	cout << endl;
//	//初始化vector对象
//	vector<int> v1(begin(a),end(a));
//	for (auto& z : v1)//数组的范围是0-100
//	{
//		cout << z << " ";
//	}
//	cout << endl;
//}
//练习 3.42 : 编写一段程序，将含有整数元素的 vector 对象拷贝给一个整型数组。
//int main()
//{
//	srand((unsigned)time(NULL));
//	vector<int> v1;
//	for (auto i = 0;i < 10;i++)//初始化vector容器
//	{
//		v1.push_back(rand()%100);
//	}
//	cout << "vector容器的数据是:" << endl;
//	for (auto i : v1)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//	auto a = v1.begin();
//	int arr[10];
//	for (auto &val : arr)
//	{
//		val = *a;
//		a += 1;
//	}
//	cout << "数组的数据是:" << endl;
//	for (auto i : arr)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//	return 0;
//}
//练习 3.43:编写3个不同版本的程序，令其均能输出 ia 的元素。版本1使用范围 for语句管理迭代过程;版本2和版本3都使用普通的 for 语句，
// 其中版本2要求用下标运算符，版本3要求甪指针。此外，在所有3个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto 关键字或 decltype 关键字。
//int main()
//{
//	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
//	cout << "版本一" << endl;
//	for (int (&row)[4] : ia)
//	{
//		for (int j : row)
//		{
//			cout << j << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	cout << "版本二" << endl;
//	for (int i = 0;i < 3;i++)
//	{
//		for (int j = 0;j < 4;j++)
//		{
//			cout << ia[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	cout << "版本三" << endl;
//	for (int(*p)[4] = ia; p != ia +3;p++)
//	{
//		for (int* q = *p;q != *p + 4;q++)//p指向含有四个整数的数组,*p是数组的第一个元素的地址值,q此时指向该数组的第一个元素
//		{
//			cout << *q << " ";
//		}
//	}
//	cout << endl;
//	return 0;
//}
//练习 3.44:改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。
//使用别名
//using int_array = int[4];//使用类型别名
//int main()
//{
//	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
//	cout << "元素为:" << endl;
//	for (auto& i : ia)
//	{
//		for (auto& j : i)
//		{
//			cout << j << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	for (int_array* p = ia;p != ia + 3;p++)
//	{
//		for (int* q = *p;q != *p + 4;q++)
//		{
//			cout << *q << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	return 0;
//}
//练习4.22:本节的示例程序将成绩划分成)high pass、 pass 种fail 三种，扩展该程序使其进一步将 60 分到 75 分之间的成绩设定为 low pass。
//要求程序包含两个版本 : 一个版本只使用条件运算符;另外一个版本使用1 - 个或多个 if 语句。哪个版本的程序更容易理解呢 ? 为什么 ?
//int main()
//{
//	//版本一
//	/*grade = (grade > 90) ? high pass : ((grade > 75) ? pass : (grade < 60) ? low pass : pass));*/
//	//版本二
//	if (grade > 90)
//	{
//		grade = high pass;
//	}
//	else if (75 <grade && grade < 90)
//	{
//		grade = pass;
//	}
//	if (grade < 75 && grade >60)
//	{
//		grade = low pass;
//	}
//	else
//	{
//		grade = fail;
//	}
//}
