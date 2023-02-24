//#include<iostream>
//#include<string>
//#include<set>
//#include<vector>
//#include<algorithm>
//#include<map>
//#include<time.h>
//using namespace std;
//#define CEHUA 0
//#define MEISHU 1
//#define YANFA 2
//class Person
//{
//public:
//	string name;
//	int salary;
//};
////员工分组
//void createWorker(vector<Person>& v)
//{
//	string nameSeed = "ABCDEFGHIJ";
//	for (int i = 0;i < 10;i++)
//	{
//		Person person;
//		person.name = "员工";
//		person.name += nameSeed[i];
//		person.salary = rand() % 100000 + 10000;
//		v.push_back(person);
//	}
//}
////实现员工分组
//void setGroup(vector<Person> &v,multimap<int, Person>&m)
//{
//	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
//	{
//		//产生随机部门编号
//		int depId = rand() % 3;//0 1 2
//		//将员工插入到分组中
//		//key为部门编号,value为具体员工
//		m.insert(make_pair(depId, *it));
//	}
//}
//void show(multimap<int, Person>& m)
//{
//	multimap <int, Person>::iterator pos = m.find(CEHUA);
//	int count = m.count(CEHUA);
//	
//	cout << "策划部门:" << endl;
//	for(int index = 0;pos != m.end() && index < count;pos++, index++)
//	{
//		cout << "姓名:" << pos->second.name << "工资" << pos->second.salary << endl;
//	}
//	cout << "----------------------" << endl;
//	cout << "美术部门:" << endl;
//	multimap <int, Person>::iterator kos = m.find(MEISHU);
//	count = m.count(MEISHU);
//	for (int index = 0;kos != m.end() && index < count;kos++, index++)
//	{
//		cout << "姓名:" << kos->second.name << "工资" << kos->second.salary << endl;
//	}
//	cout << "----------------------" << endl;
//	cout << "研发部门:" << endl;
//	multimap <int, Person>::iterator zos = m.find(YANFA);
//	count = m.count(YANFA);
//	for (int index = 0;zos != m.end() && index < count;zos++, index++)
//	{
//		cout << "姓名:" << zos->second.name << "工资" << zos->second.salary << endl;
//	}
//}
//void test01()
//{
//	vector<Person>v;
//	createWorker(v);
//	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
//	{
//		cout << "姓名" << it->name << "薪水" << it->salary << endl;
//	}
//	//员工分组
//	multimap<int, Person>m;
//	setGroup(v,m);
//	//分组显示员工
//	show(m);
//};
//int main()
//{
//	srand((unsigned)time(NULL));
//	test01();
//	/*test02();*/
//	system("pause");
//	return 0;
//}
