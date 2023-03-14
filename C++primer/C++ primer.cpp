#include<iostream>
#include<vector>
using namespace std;
//6.3.3 节练习 6.36:编写一个函数的声明，使其返回数组的引用并且该数组包含 10个 string
//对象。不要使用尾置返回类型、decltype 或者类型别名。
//string (&func())[10];
//练习 6.37 : 为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用 decltype 关键字。你觉得哪种形式最好 ? 为什么 ?
//类型别名:
//typedef string arr[10];
//arr& func();
////尾置返回类型
//auto func()->string(&)[10];
////decltype
//string str[10];
//decltype(str)& func1();
//练习 6.38 : 修改 arrptr函数，使其返回数组的引用。
//int odd[] = { 1,3,5,7,9 };
//int even[] = { 2,4,6,8,10 };
//decltype(odd)& func(int i)
//{
//	return (i % 2) ? odd : even;
//}
/*练习6.42:给make_plural函数(参见 6.3.2 节，第 201 页)的第二个形参赋予默认实参's'，利用新版本的函数输出单说司 success 和 failure 的单数和复数形式*/
//string make_plural(size_t ctr, const string& word, const string& ending = "s")
//{
//	return (ctr > 1) ? word + ending : ending;
//}
//int main()
//{
//	string s1 = "cow";
//	string s2 = make_plural(2,s1);
//	cout << "s1的复数形式:" << s2 <<endl;
//练习 6.47:改写 6.3.2节(第 205页)练习中使用递归输出 vector 内容的程序，使其有条件地输出与执行过程有关的信息。例如，每次调用时输出 vector 对象的大小。分
//别在打开和关闭调试器的情况下编译并手执行这个程序。
//void shuchu(vector<int> v1,unsigned index)
//{
//	auto size = v1.size();
//#ifndef NDEBUG
//	cout << "数组的大小为:" << size << endl;
//#endif // !NDEBUG
//	if(!v1.empty() && index < size)
//	{
//		cout << v1[index] << endl;
//		shuchu(v1, index + 1);
//	}
//	return;
//}
//int main()
//{
//	vector<int> v1 = { 5,6,2,3,4 };
//	shuchu(v1, 0);
//}
////练习 6.54:编写函数的声明，令其指接受两个 int 形参并且返回类型也是 int;然后声明一个 vector 对象，令其元素是指指向该函数的指针。
//int hanshu(int x, int y);
//
///*练习 6.55:编写4个函数，分别对两个 int 值执行加、减、乘、除*//*运算;在上一题创建的 vector 对象中保存指向这些函数的指针。*/
//int jia(int x, int y)
//{
//	return x + y;
//}
//int jian(int x, int y)
//{
//	return x - y;
//}
//int cheng(int x, int y)
//{
//	return x * y;
//}
//int chu(int x, int y)
//{
//	return x / y;
//}
//vector<decltype(hanshu)* > v1 = { jia,jian,cheng,chu };
////练习 6.56:调用上述 vector 对象中的每个元素并输出其结果。
//void shuchu(int x, int y, int func(int x1, int y1))
//{
//	cout << func(x, y)<<endl;
//}
//int main()
//{
//	int i = 5;int j = 10;
//	vector<decltype(hanshu)* > v1 = { jia,jian,cheng,chu };
//	for (auto p : v1)
//	{
//		shuchu(i, j, p);
//	}
//}
//练习 7.1:使用 2.6.1 节练习定义的 Sales data类为1.6 节(第 21 页)的交易处理程
//序编写一个新版本。
//class Salesdata
//{
//public:
//	string isbn() const { return this->name; };
//private:
//	string name;
//};
//int main()
//{
//	cout << "请输入交易{ISBN 、销售量、原价、实际售价}"<<endl;
//	Salesdata total;
//	if (cin >> total)
//	{
//		Salesdata trans;
//		while (cin >> trans)
//		{
//			if (total.isbn() == trans.isbn())
//			{
//				total += trans;
//			}
//			else
//			{
//				cout << total << endl;
//				total = trans;//使用这项数据匹配下一项输入的数据
//			}
//		}
//		cout << trans << endl;
//	}
//	else
//	{
//		cerr << "no datas!" << endl;
//		return -1;
//	}
//	return 0;
//}