//
//#include<string>
//#include"point.h"
//#include"circle.h"
//void panduan(Circle& c, Point& p)
//{
//	//计算两点之间的距离平方
//	int a = ((c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx())
//		+ (c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety()));
//	int b = c.getr() * c.getr();
//	if (a == b)
//	{
//		cout << "点在圆上" << endl;
//	}
//	else if(a < b)
//	{
//		cout << "点在圆内" << endl;
//	}
//	else
//	{
//		cout << "点在圆外" << endl;
//	}
//}
//int main()
//{
//	Circle c1;
//	c1.setr(10);
//	Point p1;//圆心
//	p1.setx(10);
//	p1.sety(0);
//	c1.setcenter(p1);
//	Point p2;
//	p2.setx(10);
//	p2.sety(9);
//	panduan(c1, p2);
//	system("pause");
//	return 0;
//}