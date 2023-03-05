#include<iostream>
#include<string>
#include<vector>
#include<iterator>
using namespace std;
//3.4.1 节练习
//练习 3.21:请使用迭代器重做 3.3.3 节 第 94 页)的第一个练习。
//template<typename elemType>
//void shuchu(vector<elemType> v)
//{
//	int x = 0;
//	cout << "容器的大小为:" << v.size() << endl;
//	if (v.cbegin() != v.cend())
//	{
//		//容器不为空
//		cout << "元素为:" << endl;
//		for (auto it = v.cbegin();it!=v.cend();it++)
//		{
//			cout << *it << " ";
//			//五个元素换行一次
//			x++;
//			if (x % 5 == 0)
//			{
//				cout << endl;
//			}
//		}
//		cout << endl;
//	}
//	else
//	{
//		cout << "抱歉您输入的容器是空的" << endl;
//	}
//}
//int main()
//{
//	vector<int> v1;//v1是空容器,int类型默认是0
//	vector<int> v2(10);//10个元素,每个元素的值为0
//	vector<int> v3(10, 1);
//	vector<int> v4{ 10,1 };
//	vector<string> v5(10, "hello");
//	shuchu(v1);
//	shuchu(v2);
//	shuchu(v3);
//	shuchu(v4);
//	shuchu(v5);
//}
//练习 3.22:修改之前那个输出 text 第 段的程序，首先把 text 的第一段全都改成大
//写形式，然后再输出它
//int main()
//{
//	vector<string> v1;
//	string s1;
//	while (getline(cin, s1))//初始化容器
//	{
//		v1.push_back(s1);
//	}
//	for (vector<string>::iterator s1 = v1.begin();s1 != v1.end() && !s1->empty();s1++)//使用getline初始化的容器,string中可能会有空白符遇到即跳过
//	{
//		//遍历vector容器
//		for (auto it2 = s1->begin();it2 != s1->end();it2++)
//		{
//			*it2 = toupper(*it2);
//			cout << *it2 << " ";
//		}
//		cout << endl;
//	}
//
//}
//练习 3.23 : 编写一段程序，创建一个含有 10 个整数的 vector 对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出 vector 对象的内容，检验程序是否正确。
//int main()
//{
//	vector<int> v1;
//	for (int i = 0;i < 10;i++)
//	{
//		v1.push_back(i);
//	}
//	cout << "改变前" << endl;
//	for (int i = 0;i < 10;i++)
//	{
//		cout << v1[i] << endl;
//	}
//	cout << "改变后" << endl;
//	for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
//	{
//		(*it) *= (*it);
//	}
//	for (int i = 0;i < 10;i++)
//	{
//		cout << v1[i] << endl;
//	}
//}
//3.4.2 节练习
//练习 3.24:请使用迭代器重做 3.3.3 节(第 94页)的最后一个练习。
//int main()
//{
//	vector<int> v1;
//	cout << "请输入:" << endl;
//	int vVal;
//	while (cin >> vVal)
//	{
//		v1.push_back(vVal);
//	}
//	cout << "相邻两元素的和为:" << endl;
//	//奇数和偶数
//	for (vector<int>::iterator it = v1.begin();it+1 != v1.end();it+=2)
//	{
//		cout << *it + *(it + 1) <<endl;
//		if (it + 2 == v1.end())
//		{
//			break;
//		}
//	}
//	if ((v1.end() - v1.begin()) % 2 != 0)
//	{
//		vector<int>::iterator it = v1.end() - 1;
//		cout << *it << endl;
//	}
//	//倒着输出
//	vector<int>::iterator it = v1.begin();
//	vector<int>::iterator eit = v1.end();
//	for (int i = 0; i!= (v1.end() - v1.begin())/2;i++)
//	{
//		cout << *it + *(eit - 1) << endl;
//		it++;
//		eit--;
//	}
//	if ((v1.end() - v1.begin()) % 2 != 0)//奇数的情况
//	{
//		vector<int>::iterator it = v1.begin() + ((v1.end() - v1.begin()) / 2);
//		cout << *it << endl;
//	}
//}
//练习 3.25 : 3.3.3 节(第 93 页)划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序并实现完全相同的功能。
//int main()
//{
//	vector<unsigned> v1(11, 0);//11个数,初始化值为0
//	auto it = v1.begin();
//	unsigned grade;
//	int x = 0;
//	while (cin >> grade)
//	{
//		if (grade < 101)
//		{
//			++* (it + grade / 10);
//			x++;
//		}
//	}
//	cout << "您总共输入了" << x << "个成绩" << endl;
//	cout << "各分数段人数的分布是:" << endl;
//	for (vector<unsigned>::iterator it = v1.begin();it != v1.end();it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//练习 3.31:编写一段程序，定义一个含有 10 个int的数组，令每个元素的值就是其下标值。
//int main()
//{
//	int arr[10];
//	for (int i = 0;i < 10;i++)
//	{
//		arr[i] = i;
//	}
//}
//练习 3.32 : 将上一题刚刚创建的数组拷贝给另外一个数组。利用 vector重写程序，实现类似的功能。
//int main()
//{
//	const int sz = 10;
//	int a[sz], b[sz];
//	for (int i = 0;i < 10;i++)
//	{
//		a[i] = i;
//	}
//	for (int i = 0;i < 10;i++)//将a数组赋值给b数组
//	{
//		b[i] = a[i];
//	}
//	vector<int> v1, v2;
//	for (int i = 0;i < 10;i++)
//	{
//		v1.push_back(i);
//	}
//	for (int i = 0;i < 10;i++)
//	{
//		v2.push_back(v1[i]);
//	}
//}
