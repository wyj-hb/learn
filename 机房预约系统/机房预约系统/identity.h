#pragma once //防止头文件重复包含
#include<iostream>
#include<fstream>
#include"globalFile.h"
#include<vector>
using namespace std;
//身份类抽象
class Idenity
{
public:
	//操作菜单 纯虚函数
	virtual void openmenu() = 0;
	//用户名
	string m_name;
	//密码
	string m_pass;
};