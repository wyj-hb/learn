//#include<iostream>
//#include<string>
//using namespace std;
//类对象作为类成员
//class Phone
//{
//public:
//	Phone(string pName)
//	{
//		p_name = pName;
//	}
//	string p_name;
//};
//class Person
//{
//public:
//	Person(string name, string pName):m_name(name),m_Phone(pName)
//	{
//
//	}
	//初始化列表初始化属性
	//Person(int a,int b,int c) :m_a(a), m_b(b), m_c(c) 
	//{

	//}
	////Person(const Person& p)
	//{
	//	cout << "Person拷贝构造函数调用" << endl;
	//	m_age = p.m_age;
	//	//m_height = p.m_height; 编译器默认实现就是这行代码
	//	//深拷贝操作
	//	m_height = new int(*p.m_height);//使拷贝后的指针指向一块新的内存空间
	//}
	//~Person()
	//{
	//	//析构代码，将堆区开辟数据做释放操作
	//	if (m_height != NULL)
	//	{
	//		delete m_height;
	//		m_height = NULL;//防治野指针的出现
	//	}
	//	cout << "析构函数" << endl;
	//}
	/*string m_name;
	Phone m_Phone;
	int m_c;
};*/
//当其他类的对象作为本类成员，构造时候先构造类对象，再构造自身，析构的顺序与构造相反
//void test01()
//{
//	Person p("张三", "苹果MAX");
//	cout << p.m_name << "使用的是" << p.m_Phone.p_name << endl;
//}
//void dowork(Person p)
//{
//
//}
//void test02()
//{
//	Person p;
//	dowork(p);
//}
////3.值方式返回局部对象
//Person dowork2()
//{
//	Person p1;
//	return p1;
//}
//void test03()
//{
//	Person p = dowork2();
//}
//int main()
//{
//	test01();
//	//test02();
//	//test03()
//	system("pause");
//	return 0;
//}