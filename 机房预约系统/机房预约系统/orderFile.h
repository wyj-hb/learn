#pragma once //防止头文件重复包含
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<functional>
#include<map>
#include<string>
class OrderFile
{
public:
	//构造函数
	OrderFile();
	//更新预约
	void updateOrder();
	//记录预约条数
	int m_size;
	//记录所有预约信息的容器 key记录条数 value 具体记录键值对信息
	map<int, map<string, string>>m_order;
};