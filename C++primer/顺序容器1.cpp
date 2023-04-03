#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<forward_list>
using namespace std;
//练习9.22 : 假定iv是一个int的vector 下面的程序存在什么错误 ? 你将如何修改 ?
//int main()
//{
//	vector<int> v1 = { 1,2,3 };
//	int some_val = 1;
//	vector<int>::iterator iter = v1.begin();
//	int org_size = v1.size();//初始大小
//	int new_size = 0;
//	while (iter != (v1.begin() + org_size / 2 +new_size))//使得iter永不超过原来中间的位置
//	{
//		if (*iter != some_val)
//		{
//			iter++;//跳过
//		}
//		else
//		{
//			iter = v1.insert(iter, 2 * some_val);//因为插入元素后迭代器会失效，因此我们需要对其进行更新
//			iter += 2;
//		}
//	}
//}
//练习 9.24 : 编写程序，分别使用at、 下标运算符、front和begin提取一个vector
//中的第一个元素。在一个空vector 上测试你的程序。
//int main()
//{
//	vector<int> v1{ 0,1,2,3 };
//	auto a = v1.front();//返回首元素的引用
//	auto b = v1[0];
//	auto c = *v1.begin();
//	auto d = c = v1.at(0);//返回首元素的引用
//}
//练习9.26 : 使用下面代码定义的ia，将 ia 拷贝到一个 vector 和一个 list 中。使
//用单迭代器版本的erase从list中删除奇数元素，从 vector 中删除偶数元素。
//int ia[] = { 0，1,1，2， 3,5, 8，13，21，55，89 };
//int main()
//{
//	int ia[] = { 0,1,1,2,3,5, 8,13,21,55,89 };
//	vector<int> v1;
//	list<int> l1;
//	v1.assign(ia, ia + 11);
//	l1.assign(ia, ia + 11);
//	vector<int>::iterator it1 = v1.begin();
//	while (it1 != v1.end())
//	{
//		if (*it1 % 2 == 0)
//		{
//			vector<int>::iterator iter = v1.erase(iter);
//		}
//		else
//		{
//			it1++;
//		}
//	}
//}
//9.3.4节练习
//练习 9.27:编写程序，查找并删除 forwar id list<int>中的奇数元素。
//int main()
//{
//	forward_list<int> f;
//	auto v1 = f.begin();
//	auto v2 = f.before_begin();
//	for (auto i : f)
//	{
//		if (i % 2 == 1)
//		{
//			f.erase_after(v2);
//		}
//		else
//		{
//			v2 = v1;
//			v1++;
//		}
//	}
//}
//练习 9.28 : 编写函数，接受一个 forward list<string>和两个 string 共三个参
//数。函数应在链表中查找第一个 string, 并将第二个 string插入到紧接着第一个
//string之后的位置。若第一个 string未在链表中，则将第二个string插入到链表末尾。
//void charu(forward_list<string> f1, string s1, string s2) 
//{
//	auto v1 = f1.begin();
//	auto v2 = f1.before_begin();
//	for (auto i : f1)
//	{
//		if (i == s1)
//		{
//			f1.insert_after(v1,s2);
//			return;
//		}
//		else
//		{
//			v2 = v1;
//			v1++;
//		}
//	}
//	f1.insert_after(v2, s2);
//}
//练习9.31 : 第程不能用于ist或 forward_list。为什么 ? 修改程序，使之也能用于这些类型。
//原因:其元素不是连续存储的，不支持加、减操作，支持加加，减减，更改为加加、减减即可.
//练习9.38 : 编写程序，探究在你的标准库实现中，vector 是如何增长的。
//int main()
//{
//	vector<int> v1;
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//	for (int i = 0;i < 5;i++)
//	{
//		v1.push_back(i);
//	}
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//	for (int i = 0;i < 5;i++)
//	{
//		v1.push_back(i);
//	}
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//	for (int i = 0;i < 5;i++)
//	{
//		v1.push_back(i);
//	}
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//}
//练习9.41 : 编写程序，从一个vector<char>初始化一个 string.
//int main()
//{
//	vector<char> v1;
//	string s(v1.data(), v1.size());//data函数用于返回v1容器的第一个元素的地址
//}
//练习9.42 : 假定你希望每次读取一个字符存入一个string中，而且知道最少需要读取100个字符，应该如何提高程序的性能 ?
//int main()
//{
//	string s;
//	s.reserve(100);//预先分配100个内存空间
//	char c;
//	while (cin >> c)
//	{
//		s.push_back(c);
//	}
//}
//练习 9.43 : 编写一个函数，接受三个 string 参数 s、 oldVal和newVal。使用迭代
//器及insert和erase函数将s中所有oldval替换为newVal。测试你的程序，用它替换通用的简写形式，如，将"tho"替换为"though"，将将"thru"替换为"through"。
//void tihuan(string &s, string oldval, string newVal)
//{
//	auto l = s.size();
//	if (!l)
//	{
//		return;
//	}
//	auto i1 = s.begin();
//	while(i1 < s.end())
//	{
//		auto i2 = i1;
//		auto i3 = oldval.begin();
//		while (i3 != oldval.end() && *i2 == *i3)
//		{
//			i2++;
//			i3++;
//		}
//		if (i3 == oldval.end())
//		{
//			//匹配成功
//			i1 = s.erase(i1, i2);
//			//此时i1指向被删除后第一个元素的位置，也就是i2的位置
//			if (newVal.size())
//			{
//				//判断字符串是否为空
//				i3 = newVal.end();
//				//从后到前依次插入数据
//				do
//				{
//					i3--;
//					i1 = s.insert(i1, *i3);
//				} while (i3 != newVal.begin());
//			}
//			i1 += newVal.size();
//		}
//		else
//		{
//			i1++;
//		}
//	}
//}
//int main()
//{
//	string s = "tho thru tho!";
//	tihuan(s, "thru", "through");
//	cout << s << endl;
//	return 0;
//}
// 练习944 : 重写上一题的函数，这次使用一个下标和re eplace.
//void tihuan(string& s, string oldval, string newVal)
//{
//	int p = 0;
//	while (p = s.find(oldval, p) != string::npos)
//	{
//		s.replace(p, oldval.size(), newVal);
//		p += oldval.size();
//	}
//}
//int main()
//{
//	string s = "tho thru tho!";
//	tihuan(s, "thru", "through");
//	cout << s << endl;
//	return 0;
//}
//练习9.45 : 编写一个函数，接受一个表示名字的string g参数和两个分别表示前缀(如"Mr."或"Ms.")和后缀(如"Jr."或"II")的字符串。使用迭代器及 insert 和 append函数将前缀和后缀添加到给定的名字中，将生成的新st ring 返回。
//void biaoshi(string &name, string q1, string q2)
//{
//	auto i = name.begin();
//	auto j = q1.begin();
//	while (j!=q1.end())
//	{
//		i = name.insert(i, *j);
//		j++;
//	}
//	name = name.append(q2);
//}
//int main()
//{
//	string s1 = "zjl";
//	string s2 = "mr";
//	string s3 = "jj";
//	biaoshi(s1, s2, s3);
//	cout << s1 << endl;
//}
//练习9.46 : 重写上一题的函数, 这次使用位置和长度来管理string, 并只使用 insert。
//void biaoshi(string &name, string q1, string q2)
//{
//	name.insert(0, " ");
//	name.insert(0, q1);
//	name.insert(name.size(), " ");
//	name.insert(name.size(), q2);//在指定的位置之前插入元素，但不会返回迭代器
//}
//int main()
//{
//	string s1 = "zjl";
//	string s2 = "mr";
//	string s3 = "jj";
//	biaoshi(s1, s2, s3);
//	cout << s1 << endl;
//}
//练习9.47 : 编写程序，首先查找 strin g"ab2c3d7R4E6"中的每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用find_first_of，第二个
//要使用 find_first_not_of.
//void find_char(string& s, const string& chars)
//{
//	cout << "在" << s << "中查找字符" << chars << endl;
//	string::size_type pos = 0;
//	while ((pos = s.find_first_of(chars, pos)) != string::npos)
//	{
//		cout << "在" << pos << "位置找到" << s[pos] << endl;
//		pos++;
//	}
//}
//int main()
//{
//	string s1 = "ab2c3d7R4E6";
//	string number = "123456789";
//	find_char(s1, number);
//}