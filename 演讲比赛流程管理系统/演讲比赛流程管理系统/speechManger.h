#pragma once//防止头文件重复编译
#include<iostream>
#include<vector>
#include"speaker.h"
#include<map>
#include<string>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<ctime>
#include<fstream>
using namespace std;
//设计演讲管理类
class SpeechManger
{
public:
	//构造函数
	SpeechManger();
	//析构函数
	~SpeechManger();
	//菜单函数
	void menu();
	//退出系统
	void exitsys();
	//初始化容器和属性
	void initspeech();
	//创建12名选手
	void createManger();
	void startSpeech();
	//比赛
	void speechContest();
	//成员属性
	//保存第一轮比赛选手编号的容器
	vector<int>v1;
	//第一轮晋级选手编号容器
	vector<int>v2;
	//胜出前三名以及对应具体选手容器
	vector<int>v3;
	map<int, speaker>m_speaker;
	//存放比赛轮数
	int m_index;
	//抽签
	void chouqian();
	//显示比赛结果
	void showscore();
	//保存文件
	void saveRecord();
	//读取记录
	void loadRecord();
	//判断文件是否为空
	bool fileIsEmpty;
	//存放往届记录的容器
	map<int, vector<string>>m_Record;
	//展示往届记录功能
	void showrecord();
	//清空记录
	void clearrecord();
};