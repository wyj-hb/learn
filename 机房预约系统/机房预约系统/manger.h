#include"identity.h"
#include<string>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerroom.h"
#pragma once //防止头文件重复包含
class manger : public Idenity
{
public:
	//默认构造
	manger();
	//有参构造 
	manger(string name, string pwd);
	//菜单界面
	virtual void openmenu();
	//添加账号
	void addperson();
	//查看账号
	void showperson();
	//查看机房信息
	void showcpm();
	//情况预约记录
	void clean();
	//初始化容器
	void initvector();
	//检测重复 参数1 检测学号/职工号 参数2 检测类型
	bool checkPepeat(int id, int type);
	//学生容器
	vector<student>vstu;
	//教师容器
	vector<teacher>vtea;
	vector<computerroom>vcom;
};