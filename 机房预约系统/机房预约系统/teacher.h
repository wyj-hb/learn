#include "identity.h"
#pragma once //防止头文件重复包含
#include<string>
#include"orderFile.h"
class teacher : public Idenity
{
public:
	//默认构造
	teacher();
	//有参构造 
	teacher(int empid, string name, string pwd);
	//菜单界面
	virtual void openmenu();
	//审核预约
	void validmyorder();
	//查看所有预约
	void lookorder();
	int m_empod;
};