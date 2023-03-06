#include"boss.h"
//显示个人信息
void boss::shpwInfo()
{
	cout << "职工编号: " << this->m_id << "\t职工姓名: " << this->name << "\t岗位: " << this->getDeptName() << "\t岗位职责: 管理公司所有事务" << endl;
}
//获取岗位名称
string boss::getDeptName()
{
	return string("总裁");
}
boss::boss(int id, string name, int Did)
{
	this->m_id = id;
	this->name = name;
	this->m_Did = Did;
}