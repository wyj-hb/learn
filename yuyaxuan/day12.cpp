//#include<iostream>;
//#include<deque>
//#include<algorithm>//标准算法头文件
//using namespace std;
////deque容器排序
//void printf(const deque<int>&d)//只读
//{
//	for (deque<int> ::const_iterator it = d.begin();it != d.end();it++)
//	{
//		//*it = 100; 失败，容器不可以修改
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	deque<int>d1;
//	d1.push_back(10);
//	d1.push_back(20);
//	d1.push_back(30);
//	d1.push_front(100);
//	d1.push_front(200);
//	d1.push_front(300);
//	printf(d1);
//	cout << "排序后" << endl;
//	sort(d1.begin(), d1.end());
//	printf(d1);//默认从小到大 升序
//	//对于支持随机访问的迭代器，都可以利用sort算法对其进行排序 例如vector
//}
//void test02()
//{
//	deque<int>d1;
//	d1.push_back(10);
//	d1.push_back(20);
//	d1.push_front(100);
//	d1.push_front(200);
//	printf(d1);
//	d1.insert(d1.begin(), 1000);
//	printf(d1);
//	d1.insert(d1.begin(),2,10000);
//	printf(d1);
//	//按照区间进行插入
//	deque<int>d2;
//	d2.push_back(1);
//	d2.push_back(2);
//	d2.push_back(3);
//	d1.insert(d1.begin(), d2.begin(), d2.end());//d1 begin的位置开始插入
//	printf(d1);
//}
//void test03()
//{
//	deque<int>d1;
//	d1.push_back(10);
//	d1.push_back(20);
//	d1.push_front(100);
//	d1.push_front(200);
//	//200 100 10 20 
//	//删除
//	deque<int>::iterator it = d1.begin();
//	it++;
//	d1.erase(it);
//	printf(d1);	//200 10 20
//	d1.erase(d1.begin(), d1.end());
//	//清空
//	d1.clear();
//}//插入和删除提供的位置是迭代器!
//int main()
//{
//	test01();
//	/*test02();*/
//	/*test03();*/
//	system("pause");
//	return 0;
//}