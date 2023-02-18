#include<iostream>
#include<string>
#include<fstream>
//using namespace std;
////二进制文件 读文件
//class Person
//{
//public:
//	char m_Name[50];
//	int m_Age;
//};
//void test01()
//{
//	//1.包含头文件
//	//2.创建流对象
//	ifstream ifs;//2、3也可以合并为ofstream ofs("person.txt", ios::out | ios::binary)
//	//3.打开文件并判断是否打开成功
//	ifs.open("person.txt", ios::in | ios::binary);
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//	}
//	//4.写文件
//	Person p;
//	ifs.read((char *)&p, sizeof(Person));//第一个参数为要读到哪，第二个为数据大小
//	cout << "姓名:" << p.m_Name << "年龄:" << p.m_Age << endl;
//	//5.文件关闭
//	ifs.close();
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}