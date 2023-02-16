//#include<iostream>
//#include<string>
//using namespace std;
//void show(const int& ref)//int* const ref = &a
//{
//	//ref = 1000 错误，无法再修改，这样可以防止误操作
//	cout << ref << endl;
//}
//int main()
//{
//	//常量引用
//	//使用场景:用来修饰形参防止误操作
//	int a = 10;
//	int& ref = a;//int &ref = 10 错误
//	const int& ref1 = 10;//正确
//	//ref = 20 错误，变成只读，不可修改
//	show(ref);
//	system("pause");
//}