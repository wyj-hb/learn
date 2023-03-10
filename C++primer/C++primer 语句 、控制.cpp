#include<iostream>
using namespace std;
//6.1.2 节练习
//练习 6.8:编写一个名为 Chapter6.h的头文件，令其包含 6.1 节练习(第 184 页)中的函数声明。
//练习 6.9:编写你自己的 fact.cc 和 factMain.cc，这两个文件都应该包含上一小节的练习中编写的 Chapter6.h 头文牛。
//通过这些文件，理解你的编译器是如何支持分离式编译的。
//练习 6.10:编写一个函数，使用指针形参不交换两个整数的值。在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。
//void jiaohuan(int* q, int* p)
//{
//	int temp = *q;
//	*q = *p;
//	*p = temp;
//}
//int main()
//{
//	int arr1 = 10;
//	int arr2 = 100;
//	int* p1;
//	int* p2;
//	p1 = &arr1;
//	p2 = &arr2;
//	cout << "交换前：" << endl;
//	cout << *p1 << *p2 << endl;
//	jiaohuan(p1, p2);
//	cout << "交换后：" << endl;
//	cout << *p1 << *p2 << endl;
//}
//.6.2 节练习
//练习 6.11:编写并验证你自己的 reset 函数，使其作用于引用类型的参数。
//void reset(int& i)//引用
//{
//	i = 0;
//}
//int main()
//{
//	int i = 100;
//	cout << "更改前" << endl;
//	cout << i << endl;
//	reset(i);
//	cout << "更改后" << endl;
//	cout << i << endl;
//}
//练习 6.12 : 改写 6.2.1 节中练习 6.10(第 188 页)的程序，使用引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢 ? 为什么 ?
//void jiaohuan(int& q, int& p)
//{
//	int temp = q;
//	q = p;
//	p = temp;
//}
//int main()
//{
//	int p1 = 10;
//	int p2 = 100;
//	cout << "交换前：" << endl;
//	cout << p1  << p2 << endl;
//	jiaohuan(p1, p2);
//	cout << "交换后：" << endl;
//	cout << p1  << p2 << endl;
//}32222222
//练习 6.23 : 参考本节介绍的几个 print 函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j :
//int i = 0，j[2] = { 0，1 };
//void print1(const int* p)
//{
//	cout << *p << endl;
//}
//void print2(const int* p, const int sz)
//{
//	for (int i = 0;i < sz;i++)
//	{
//		cout << *p << endl;
//		p++;
//	}
//}
//void print3(const int* p1, const int* p2)
//{
//	for (auto p = p1;p != p2;p++)
//	{
//		cout << *p << endl;
//	}
//}
//练习 6.25: 编写一个 main 函数, 令其接受两个实参。把实参的内容连接成一个string对象并输出出来。
//int main(int argc, char** argv)//argv是一个数组，数组中的元素是字符串
//{
//	string str;
//	for (int i = 0;i != argc;i++)
//	{
//		str += argv[i];
//	}
//	cout << str << endl;
//	return 0;
//}
//练习 6.26 : 编写一个程序，使其接受本大节所示的选项;输出传递给 main 函数的实参的内容。
//int main(int argc,char **argv)
//{
//	for (int i = 0;i != argc;i++)
//	{
//		//输出实参的内容
//		cout << argv[i]<<" "<< endl;
//	}
//}
//练习 6.27:编写一个函数，它的参数是initializer list<int>类型的对象，函数的功能是计算列表中所有元素的和。
//int qiuhe(initializer_list<int> i1)
//{
//	int count = 0;
//	for (auto val : i1)
//	{
//		count += val;
//	}
//	return count;
//}
//int main()
//{
//	int x = qiuhe({ 10,20,30,120,20,120,10,20,30,10 });
//	cout << x << endl;
//}