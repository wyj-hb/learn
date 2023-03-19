#include<iostream>
#include<string>
using namespace std;
//7.1.3 节练习
//练习 7.6:对于函数 add、read和print，定义你自己的版本。
class Sales_data
{
	friend Sales_data add(const Sales_data& rh1, const Sales_data& rh2);
	friend istream& read(istream& is, Sales_data rhs);
	friend ostream& print(ostream& os, const Sales_data s);
	//设置为友元后即使属性变为了private也是可以访问的
public:
	double avg_price()const;//类内部的成员函数默认是内联的(隐式内联)
	//{
	//	if (units_sold)//存在销售量
	//	{
	//		return revenue / units_sold;
	//	}
	//	else
	//	{
	//		return 0;
	//	}
	//}
	//使用委托构造函数重写
	/*Sales_data(const string& bookNo, const unsigned num, const double sellp, const double salep) : bookno(bookNo), units_sold(num), saleprice(sellp), sellingprice(salep)
	{
		if (sellingprice != 0)
		{
			discount = saleprice / sellingprice;
		}
	}
	Sales_data(const string& bookno) : Sales_data(bookno, 0, 0, 0)
	{
		cout << "接受用户输入的书号信息" << endl;
	}
	Sales_data() : Sales_data("", 0, 0, 0)
	{
		cout << "没有收到任何信息" << endl;
	}
	Sales_data(std::istream &is) : Sales_data()
	{
		read(is, *this);
		cout << "接受用户输入的信息" << endl;
	}*/
	Sales_data() = default;//默认构造函数
	Sales_data(const string& bookNo) : bookno(bookNo) {};
	Sales_data(const string& bookNo, const unsigned num, const double sellp, const double salep) : bookno(bookNo), units_sold(num), saleprice(sellp), sellingprice(salep)
	{
		if (sellingprice != 0)
		{
			discount = saleprice / sellingprice;
		}
	}
	Sales_data(const string& bookNo, const unsigned num, const double sellp, const double salep, const string discount) : bookno(bookNo), 
		units_sold(0), saleprice(0), sellingprice(0), discount(0) {};
	Sales_data(istream& is);
	string isbn() const{ return this->bookno; };
	Sales_data& combine(const Sales_data& s1);
	string bookno;//书籍编号
	unsigned units_sold = 0;//销售量
	double revenue = 0.0;//总销售量
	double discount = 0.0;
	double saleprice = 0.0;//实际售出价格
	double sellingprice = 0.0;//原始价格
};
inline double Sales_data::avg_price() const
{
	if (units_sold)//存在销售量
	{
		return revenue / units_sold;
	}
	else
	{
		return 0;
	}
}
//Sales_data::Sales_data(istream &is)//没有重写
//{
//	is >> *this;
//}
Sales_data& Sales_data::combine(const Sales_data& s1)
{
	units_sold += s1.units_sold;
	saleprice = (s1.sellingprice * s1.units_sold + sellingprice * units_sold) / (s1.units_sold + units_sold);//合并后的平均实际销售价格
	if (sellingprice != 0)//原始价格不为0，存在折扣
	{
		discount = saleprice / sellingprice;//原始价格是一样的.
	}
}
Sales_data add(const Sales_data& rh1, const Sales_data& rh2)
{
	Sales_data sum = rh1;
	sum.combine(rh2);
	return sum;
}
istream& read(istream& is, Sales_data rhs)//读取rhs的信息到is流中
{
	is >> rhs.bookno >> rhs.units_sold >> rhs.sellingprice >> rhs.saleprice;
	return is;
}
ostream& print(ostream& os, const Sales_data s)
{
	os << s.isbn() << " " << s.units_sold << " " << s.sellingprice << " " << s.saleprice << " " << s.discount << " " << endl;
}
//练习 7.7 : 使用这些新函数重写 7.1.2 节(第 233 页)练习中的交易处理程序
//交易处理程序
int main()
{
	cout << "请输入交易记录:(ISBN、销售量、原价、实际售价)" << endl;
	Sales_data total;
	if (read(cin,total))
	{
		Sales_data trans;
		while (read(cin, trans))
		{
			if (trans.bookno == total.bookno)
			{
				total = add(total,trans);
			}
			else
			{
				print(cout,total);
				total = trans;
			}
		}
		print(cout, trans);
		cout << endl;
	}
	else
	{
		cout << "您的输入有误，请重新检查" << endl;
	}
	return 0;
}
//练习 7.9 : 对于 7.1.2 节(第 233 页)练习中的代码，添加读取和打印 Person 对象的操作。
//class Person
//{
//private:
//	string strName;//姓名
//	string strAddress;//地址
//public:
//	Person(const string& strName, const string& strAddress) : strName(strName), strAddress(strAddress) {};
//	string getname() const{ return strName; };
//	string getAddress() const{ return strAddress; };
//
//};
//istream& read(istream& s1, Person s2)
//{
//	s1 >> s2.getname() >> s2.getAddress();
//	return s1;
//}
//ostream& print(ostream& s1, const Person s2)
//{
//	s1 << s2.getname() << s2.getAddress();
//	return s1;
//}
//练习 7.11:在你的 Sales data 类中添忝加构造函数，然后编写一段程序令其用到每个构造函数。
//int main()
//{
//	Sales_data s1;//默认构造
//	Sales_data s2("dsiuh");
//	Sales_data s3("sidaj", 15, 12.0, 51);
//	Sales_data s4(cin);
//	return 0;
//}
////练习 7.13 : 使用 istream 构造函数重写第 229 页的程序。
//int main()
//{
//	cout << "请输入交易记录:(ISBN、销售量、原价、实际售价)" << endl;
//	Sales_data total(cin);
//	if (cin)
//	{
//		Sales_data trans(cin);
//		do
//		{
//			if (trans.bookno == total.bookno)
//			{
//				total = add(total, trans);
//			}
//			else
//			{
//				print(cout, total);
//				total = trans;
//			}
//		} while (read(cin, trans));
//	print(cout, trans);
//	cout << endl;
//	}
//	else
//	{
//		cout << "您的输入有误，请重新检查" << endl;
//	}
//	return 0;
//}
//练习7.14 : 编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。
//练习 7.15 : 为你的 Person 类添加正确的构造函数。
//练习 7.23:编写你自己的 screen 类。
class Window_mgr
{
public:
	void clear();
};
class Screen
{
	friend void Window_mgr::clear();
public:
	Screen() = default;
	Screen(unsigned height, unsigned width) : height(height), width(width), contents ( height * width,' ') {};
	Screen(unsigned height, unsigned width,char c) : height(height), width(width), contents(height * width,c) {};
	Screen& move(unsigned r, unsigned c)
	{
		cursor = r * width * c;
		return *this;
	}
	Screen& set(char c)//当前光标位置放置c
	{
		contents[cursor] = c;
		return *this;
	}
	Screen& set(unsigned r, unsigned c, char ch)//选中特定的位置放置c
	{
		contents[r * width + c] = ch;
		return *this;
	}
	Screen& display()
	{
		cout << contents;
		return *this;
	}
private:
	unsigned height = 0, width = 0;//屏幕的高度和宽度
	unsigned cursor = 0;//光标的当前位置
	string contents;//屏幕的内容
};
//练习 7.24 : 给你的 Screen 类添加三个构造函数 : 一个默认构造函数;另一个构造函数接受宽和高的值，然后将 contents
//初始化成给定数量的空白;第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容。
//练习 7.25:Screen 能安全地依赖于拷贝和赋值操作的默认版本吗 ? 如果能，为什么 ? 如果不能，为什么 ?
// 如果Screen类中的数据成员有指针类,那么使用这些构造函数会出现问题(拷贝是两个指针都指向同一个位置,一个指针被释放掉后那个位置的空间被释放，但是拷贝出来的指针仍会对
// 那片空间进行操作，因此这样的以上的拷贝函数对于指针类型的数据成员来说是危险的)，本题都是内置数据类型，所以无影响。
//练习 7.26 : 将 Sales_data::avg_price 定义成内联函数。
//练习 7.27:给你自己的 Screen 类添加 move、set 和 display 函数，通过执行下面的代码检验你的类是否正确。
//练习 7.28: 如果 move、set 和 display 函数的返回类型不是 Screen & 而是 Screen, 则在上一个练习中将会发生什么情况 ?
//如果返回的不是Screen对象的引用的话,那么就是赋值创建了一个新的副本,连续调用三个函数各个函数每次返回的Screen数据都不是同一个，无法达到预期对于同一个对象进行处理的效果
//练习 7.31:定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为 X的对象。
//class X;//声明X
//class Y
//{
//	X* x;//此时的类X是不完全类型的指针,我们可以声明指向它的类型的指针但是我们不能声明它的对象，因为X还没有定义，编译器也不知道要为定义为X对象的数据分配多大的内存
//};
//class X
//{
//	Y y;//可以声明Y类型的对象，因为Y已将完成声明
//}
//练习 7.32 : 定义你自己的 Screen 和w Window_mgr，其中clear是Wind                  ow_mgr的成员，是 Screen 的友元。
//一个类的成员函数是另一个类的友元
//void Window_mgr::clear()
//{
//	Screen myScreen(10, 10, 'X');
//	cout << myScreen.contents << endl;//作为Screen的友元可以使用
//}
//练习 7.38:有些情况下我们希望提供 ci n 作为接受 istream & 参数的构造函数的默认实参，请声明这样的构造函数。
//Sales_data(istream& is = cin) { return *this; };
//练习 7.39 : 如果接受 string 的构造函数和接受 istream & 的构造函数都使用默认实参，这种行为合法吗 ? 如果不，为什么 ?
//如果我们在创建对象时不提供任何的参数，那么编译器就不知道该调用哪个函数，因为都提供了默认实参，相当于都是默认构造函数，因而产生二义性
//练习 7.40:从下面的抽象概念中选择一个(或者你自己指定一个)，思考这样的类需要哪些数据成员，提供一组合理的构造函数数并阐明这样做的原因。
//(a) Book(b) Date(c) Employee
//(d) Vehicle(e)object(f) Tree
//class Book
//{
//public:
//	Book() = default;
//	Book(istream& is) { is >> *this; };
//	Book(const string n1, const string n2, double price, const string n4, const string n5)
//	{
//		name = n1;
//		isbn = n2;
//		this->price = price;
//		author = n4;
//		publisher = n5;
//	}
//private:
//	string name, isbn, author, publisher;
//	double price = 0;
//};
//练习 7.41:使用委托构造函数重新编写你的 Sales data类，给每个构造函数体添加
//一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建 Sales data对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。
//练习 7.42 : 对于你在练习 7.40(参见 7.5.1 节，第 261 页)中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。
//如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。
//练习 7.43:假定有一个名为 NoDefault 的类，它有一个接受 int 的构造函数，但是没有默认构造函数。定义类 c，C有一个 NoDefault类型的成员，定义c的默认构造函数。
//class NoDefault
//{
//public:
//	NoDefault(int x) { val = x; };//创建了构造函数，类便不会创建默认的构造函数,因此下面定义的nd是未定义
//	int val;
//};
//class C
//{
//public:
//	NoDefault nd;
//	C(int i = 0) : nd(i) {};//需要显示的定义
//};
//int main()
//{
//	C c;
//	cout << c.nd.val<< endl;
//	return  0;
//}
//练习7.44 : 下面这条声明合法吗 ? 如果不，为什么 ?
//vector<NoDefault> vec(10);
//错误,该语句的含义是定义一个vector,vector中数据的类型是Nodefault,共十个数据,但是由于未定义其默认函数，所以编译失败。
//练习 7.46 : 下面哪些论断是不正确的 ? 为什么 ?
//(a)一个类必须至少提供一个构造函数。错误 默认
//练习7.52:使用2.6.1节(第64页)的sales data类，解释下面的初始化过程。如
//果存在问题，尝试修改它。、
//Sales data item = { "978-0590353403" 25，15.99 };
//Sales_data类不是聚类,去除掉初始值
//练习 7.53:定义你自己的 Debug。
class Debug
{
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) {};
	constexpr Debug(bool h, bool i, bool o) :hw(h), io(i), other(o) {};
	constexpr bool any() { return hw || io || other; };//检测是否出现错误,无论是什么错误
	void set_io(bool b) { io = b; };
	void set_hw(bool b) { hw = b; };
	void set_other(bool b) { other = b; };
private:
	bool hw;//硬件错误
	bool io;//IO错误
	bool other;//其他错误
};
//练习 7.57 : 编写你自己的 Account 类。
//class Account
//{
//private:
//	string strName;
//	double dAmount = 0.0;
//	static double dRate;
//};
//练习 7.58 : 下面的静态数据成员的声明和定义有错误吗 ? 请解释原因。
//// example.h
//class Example {
//public:
//	static double rate = 6.5;
//	static const int vecsize = 20;
//	static vector<double> vec(vecsize);
//};
//// example.c
//#include "example.h" double Example::rate;
//vector<double> Example::vec;
//类型为const的静态成员变量可以在类内初始化,其他的需要在类外定义初始化。本例中.h文件中rate和vec错误，.c文件中vec和rate应该初始化