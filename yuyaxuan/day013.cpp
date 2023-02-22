//#include<iostream>
//using namespace std;
//#include<vector>
//#include<string>
//#include<deque>
//#include<time.h>
//#include<stdlib.h>
//#include<algorithm>
//class Person
//{
//public:
//	Person(string name, int score)
//	{
//		this->m_name = name;
//		this->m_Score = score;
//	}
//	string m_name;
//	int m_Score;
//};
//void createPerson(vector<Person>& v)
//{
//	string nameSeed = "ABCDE";
//	for (int i = 0;i < 5;i++)
//	{
//		string name = "选手";
//		name += nameSeed[i];
//		int score = 0;
//		Person p(name, score);
//		v.push_back(p);
//	}
//
//}
//void setScore(vector<Person>& v)
//{
//	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
//	{
//		//将评委的分数放入到deque容器中
//		deque<int>d;
//		
//		for (int i = 0;i < 10;i++)
//		{	
//			int score = rand() % 41 + 60;
//			d.push_back(score);
//		}
//		//排序
//		sort(d.begin(), d.end());
//		//去除最高分与最低分
//		d.pop_back();
//		d.pop_front();
//		//取平均分
//		int sum = 0;
//		for (deque<int>::iterator dit = d.begin();dit != d.end();dit++)
//		{
//			sum += *dit;//累加每个评委的分数
//		}
//		//计算平均分
//		int avg = sum / d.size();
//		//将平均分赋值给选手身上
//		it->m_Score = avg;
//	}
//}
//void showScore(vector<Person>& v)
//{
//	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
//	{
//		cout << "姓名:" << it->m_name << "成绩:" << it->m_Score <<endl;
//	}
//}
//int main()
//{
//	srand((unsigned)time(NULL));
//	//1.创建5名选手
//	vector<Person>v;
//	createPerson(v);
//	//2.给5名选手打分
//	setScore(v);
//	//3.显示
//	showScore(v);
//}