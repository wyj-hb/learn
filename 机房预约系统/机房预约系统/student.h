#include "identity.h"
#pragma once //防止头文件重复包含
#include"computerroom.h"
#include"globalFile.h"
#include"orderFile.h"
class student : public Idenity
{
public:
	//默认构造
	student();
	//有参构造 
	student(int id, string name, string pwd);
	//菜单界面
	virtual void openmenu();
	//申请预约
	void applyorder();
	//查看自身预约
	void showmyorder();
	//查看所有预约
	void lookorder();
	//取消预约
	void quxiao();
	int m_id;
	vector<computerroom>vcom;
};