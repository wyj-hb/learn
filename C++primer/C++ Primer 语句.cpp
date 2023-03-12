#include<iostream>
#include<vector>
using namespace std;
//6.3.2 / 节练习
//练习 6.30:编译第 200 页的 str_subrai nge 函数，看看你的编译器是如何处理函数中的错误的。
//错误:1.可能不会用到return
//2.返回值错误
//bool str_subrange(const string& str1, const string& str2)
//{
//	if (str1.size() == str2.size())
//	{
//		return str1 == str2;
//	}
//	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();//size为最长字符串的大小
//	for (decltype(size) i = 0;i < size;i++)
//	{
//		if (str1[i] != str2[i])
//		{
//			return;
//		}
//	}
//}
//练习 6.32 : 下面的函数合法吗 ? 如果合法，说明其功能;如果不合法，修改其中的错误并解释原因。
//int& get(int* arry, int index(return arry[index]; }
//int main() 
// {
//int ia[10];
//for (inti = 0;i != 10; ++i)
//get(ia, i) = i;
//合法，可以当左值
//练习6.33:编写一个递归函数，输出 ve ector 对象的内容。
//void digui(vector<int> v1,unsigned index)
//{
//	auto sz = v1.size();
//	if (index < sz)
//	{
//		cout << v1[index] << endl;
//		digui(v1, index + 1);
//	}
//	else
//	{
//		return;
//	}
//}
//int main()
//{
//	vector<int> v1;
//	for (int i = 0;i < 10;i++)
//	{
//		v1.push_back(i);
//	}
//	digui(v1,0);
//}
//练习 6.34 : 如果 factorial 函数的停 上条件如下所示，将发生什么情况 ?
//if (val != 0)
// 可以为负数，一直递归下去