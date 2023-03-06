#pragma once//防止头文件重复包含
#include<iostream>
#include<string>
using namespace std;//使用标准命名空间
class worker
{
public:
	//显示个人信息
	virtual void shpwInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;
	//职工编号
	int m_id;
	//职工姓名
	string name;
	//部门编号
	int m_Did;
};