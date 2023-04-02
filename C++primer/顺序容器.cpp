#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<deque>
using namespace std;
//练习 9.2:定义一个list对象，其元素素类型是 int 的 deque。
//list<deque<int>> l1;
//练习 9.4 : 编写函数，接受一对指向 vector<int>的迭代器和一个int 值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。
//bool panduan(vector<int>::iterator it1, vector<int>::iterator it2, int val)
//{
//	while (it1 != it2)
//	{
//		if (*it1 == val)
//		{
//			return true;
//		}
//		it1++;
//	}
//	return false;
//}
//练习9.5 : 重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。
//vector<int>;;iterator panduan(vector<int>::iterator it1, vector<int>::iterator it2, int val)
//{
//	while (it1 != it2)
//	{
//		if (*it1 == val)
//		{
//			return it1;
//		}
//		it1++;
//	}
//	return it2;
//}
//练习9.6 : 下面程序有何错误 ? 你应该如何修改它 ?
//list < int>1st1;
//list<int>::iterator iterl = lstl.begin(),
//iter2 = lstl.end();
//while (iterl < iter2)
//list不可以大小比较
//练习9.11:对6种创建和初始化vector时象的方法，每一种都给出一个实例。解释每个vector包含什么值。
//vector<int> v1;
//vector<int> v2(v1);
//vector<int> v3 = { 1,2,3,4 };
//vector<int> v4 (v3.begin(), v3.end() - 1);
//vector<int> v5(7);
//vector<int> v6(7, 3);
//练习9.15:编写程序，判定两个 vector<int>是否相等。
//bool panduan(vector<int>v1, vector<int>v2)
//{
//	return v1 == v2;
//}
//练习9.16 : 重写上一题的程序，比较一个 list<int>中的元素和一个 vector<int>中的元素。
//bool panduan(vector<int>v1, list<int>l2)
//{
//	//使用循环遍历
//}
//练习9.18:编写程序，从标准输入读取 string 序列，存入一个 deque 中。编写一个循环，用迭代器打印 deque 中的元素。。
//int main()
//{
//	deque<string> d1;
//	string word;
//	while (cin >> word)
//	{
//		d1.push_back(word);
//	}
//	for (auto i : d1)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//}
//练习 9.20 : 编写程序，从一个 list<int>拷贝元素到两个 deque 中。值为偶数的所有元素都拷贝到一个 deque 中，而奇数值元素都拷贝到另一个 deque 中。
//int main()
//{
//	list<int> l1;
//	deque<int> d1;
//	deque<int> d2;
//	for (auto i : l1)
//	{
//		if (i & 1)
//		{
//			//是结束
//			d1.push_back(i);
//		}
//		else
//		{
//			d2.push_back(i);
//		}
//	}
//}
