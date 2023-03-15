#include<iostream>
using namespace std;
//7.1.2 节练习
//练习 7.2:曾在 2.6.2 节的练习(第 67 页夏)中编写了一个 Sales_data 类，请向这个类添加 combine 和 isbn 成员。
//class Sales_data
//{
//private:
//	string bookno;//书籍编号,隐式初始化为空串
//	unsigned units_sold = 0;//销售量，显示初始化为0
//	double sellingprice = 0.0;//原始价格,初始化为0.0
//	double sellprice = 0.0;//实售价格,初始化为0.0
//	double discount = 0.0;//折扣
//public:
//	string isbn() { return bookno; };
//	Sales_data& combine(const Sales_data s1)
//	{
//		this->units_sold += s1.units_sold;//销售量相加
//		sellprice = (s1.sellprice * s1.units_sold + sellprice * units_sold) / (units_sold + s1.units_sold);//重新计算销售单价
//		if (sellingprice != 0)
//		{
//			discount = sellprice / sellingprice;//重新计算折扣
//		}
//		return *this;
//	}
//}
//练习 7.4 : 编写一个名为 Person 的类， 使其表示人员的姓名和住址。使用 string 对
//象存放这些元素，接下来的练习将不断充实这个类的其他特征。
class Person
{
private:
	string name;
	string address;
public:
	string name() const{ return this->name; };
	string address() const{ return this->address; };
};