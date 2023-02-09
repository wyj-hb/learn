#include"speechManger.h"
using namespace std;
//构造函数
SpeechManger::SpeechManger()
{
	this->initspeech();
	//创建12名选手
	this->createManger();
	//加载往届记录
	this->loadRecord();
}
//析构函数
SpeechManger::~SpeechManger()
{

}
//菜单功能
void SpeechManger::menu()
{
	cout << "************************************" << endl;
	cout << "**********欢迎参加演讲比赛**********" << endl;
	cout << "********** 1.开始演讲比赛 **********" << endl;
	cout << "********** 2.查看往届记录 **********" << endl;
	cout << "********** 3.清空比赛记录 **********" << endl;
	cout << "********** 0.退出比赛程序 **********" << endl;
	cout << "************************************" << endl;
	cout << endl;

}
void SpeechManger::exitsys()
{
	cout << "欢迎您下次使用" << endl;
	exit(0);
}
void SpeechManger::initspeech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_speaker.clear();
	this->m_Record.clear();
	//初始化比赛轮数
	this->m_index = 1;
}
void SpeechManger::createManger()
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0;i < nameseed.size();i++)
	{
		string name = "选手";
		name += nameseed[i];
		speaker sp;
		sp.m_name = name;
		for (int j = 0;j < 2;j++)
		{
			sp.m_score[j] = 0;
		}
		//创建选手编号以及对应轩后 放入到map容器中
		this->v1.push_back(i + 10001);
		//选手编号以及对应选手 放入到map容器中
		this->m_speaker.insert(make_pair((i + 10001), sp));
	}
}
//抽签
void SpeechManger::chouqian()
{
	cout << "第<<" << this->m_index << ">>轮选手正在抽签" << endl;
	cout << "----------------------------" << endl;
	cout << "抽签结果如下" << endl;
	if (this->m_index == 1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin();it != v2.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "----------------------" << endl;
	system("pause");
	cout << endl;
}
void SpeechManger::speechContest()
{
	cout << "-------第" << this->m_index << "轮比赛正式开始--------" << endl;
	vector<int>v_src;//选手比赛容器
	//准备临时容器 存放小组成绩
	int num = 0;
	multimap<double, int, greater<double>>groupScore;//key值可能是重复的，因此需要使用multimap来声明
	if (this->m_index == 1)
	{
		v_src = v1;
	}
	else
	{
		v_src = v2;
	}
	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_src.begin();it != v_src.end();it++)
	{
		//评委打分
		//容器嵌套容器
		
		deque<double>d;//记录6人一组
		num++;
		for (int i = 0;i < 10;i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//.f表示结果是一个浮点数
			/*cout << score << " ";*/
			d.push_back(score);
		}
		sort(d.begin(), d.end(),greater<double>());//排序
		d.pop_front();//去掉最高分
		d.pop_back();//去掉最低分
		double sum = accumulate(d.begin(), d.end(), 0.0f);//总分
		double avg = sum / (double)d.size();//平均分
		/*cout << avg << " ";*/
		//打印平均分
		/*cout << "编号" << *it << "姓名:" << this->m_speaker[*it].m_name << "获取平均分" << avg << endl;*/
		//将平均分放入到map容器中
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;
		//将打分数据 放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it));//key是得分，value是具体选手编号
		if (num % 6 == 0)//此时容器大小为6
		{
			cout << "第" << num / 6 << "小组比赛名次: " << endl;
			for (multimap<double, int, greater<double>>::iterator zit = groupScore.begin();zit != groupScore.end();zit++)
			{
				cout << "编号：" << zit->second << "姓名：" << this->m_speaker[zit->second].m_name << "成绩:" << zit->first << endl;
			}
			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator sit = groupScore.begin();sit != groupScore.end() && count < 3;sit++, count++)
			{
				if (this->m_index == 1)
				{
					v2.push_back(sit->second);
				}
				else
				{
					v3.push_back(sit->second);
				}
			}
			groupScore.clear();//清空容器
		}
	}
	cout << "-------第" << this->m_index << "轮比赛完毕!-------" << endl;
	system("pause");
}
void SpeechManger::showscore()
{
	cout << "-------第" << this->m_index << "轮晋级选手信息如下--------" << endl;
	vector<int>v;
	if (this->m_index == 1)
	{
		v = v2;
	}
	else
	{
		v = v3;
	}
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "选手编号：" << *it << "姓名：" << this->m_speaker[*it].m_name << "得分：" << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->menu();
}
void SpeechManger::saveRecord()
{
	ofstream ofs;
	ofs.open("D:\\niu\\speech.csv", ios::out | ios::app);//用追加的方式写文件
	//将每个选手数据 写入到文件中
	for (vector<int>::iterator it = v3.begin();it != v3.end();it++)
	{
		ofs << *it << "," << this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	cout << "信息保存完毕" << endl;
	//关闭
	ofs.close();
	//更改文件不为空的状态
	this->fileIsEmpty = false;
}
void SpeechManger::startSpeech()
{
	//第一轮开始比赛
	//1.抽签
	this->chouqian();
	//2.比赛
	this->speechContest();
	//3.显示比赛结果
	this->showscore();
	//第二轮比赛
	this->m_index++;
	//1.抽签
	this->chouqian();
	//2.比赛
	this->speechContest();
	//3.显示比赛结果
	this->showscore();
	//4.保存记录
	this->saveRecord();
	cout << "本届比赛结束！" << endl;
	this->initspeech();
	//创建12名选手
	this->createManger();
	//加载往届记录
	this->loadRecord();
	system("pause");
	system("cls");
}
void SpeechManger::loadRecord()
{
	int index = 0;
	ifstream ifs("D:\\niu\\speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		/*cout << "文件不存在" << endl;*/
		ifs.close();
		return;
	}
	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		/*cout << "文件为空" << endl;*/
		this->fileIsEmpty = true;
		return;
	}
	//文件不为空
	ifs.putback(ch);//将上面读取的单个字符放回
	string data;
	while (ifs >> data)
	{
		/*cout << data << endl;*/
		vector<string>v;//存放6个字符串
		int pos = -1;//查到，的位置
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//没有找到
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	for (map<int, vector<string>>::iterator it = m_Record.begin();it != m_Record.end();it++)
	{
		cout << it->first << "冠军编号：" << it->second[0] << "分数：" << it->second[1] << endl;
	}
}
void SpeechManger::showrecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空或者不存在" << endl;
	}
	else
	{
		for (int i = 0;i < this->m_Record.size();i++)
		{
			cout << "第" << i + 1 << "届" << "冠军编号：" << this->m_Record[i][0] << "得分" << this->m_Record[i][1] << " "
				<< "亚军编号：" << this->m_Record[i][2] << "得分" << this->m_Record[i][3] << " "
				<< "冠军编号：" << this->m_Record[i][4] << "得分" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}
void SpeechManger::clearrecord()
{
	cout << "是否清空文件" << endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//确认清空
		ofstream ofs("D:\\niu\\speech.csv", ios::trunc);//trunc文件如果存在便会被清空
		ofs.clear();
		this->initspeech();
		//创建12名选手
		this->createManger();
		//加载往届记录
		this->loadRecord();
	}
	system("pause");
	system("cls");
}