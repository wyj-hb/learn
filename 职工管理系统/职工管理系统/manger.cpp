#include"manger.h"
//显示个人信息
void manger::shpwInfo()
{
	cout << "职工编号: " << this->m_id << "\t职工姓名: " << this->name << "\t岗位: " << this->getDeptName() << "\t岗位职责: 完成老板交给的任务，并下放给员工" << endl;
}
//获取岗位名称
string manger::getDeptName()
{
	return string("经理");
}
manger::manger(int id,string name, int Did)
{
	this->m_id = id;
	this->name = name;
	this->m_Did = Did;
}