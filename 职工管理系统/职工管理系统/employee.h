//普通职工文件
#include"worker.h";
class Employee :public worker
{
public:
	//重写父类虚函数
	//显示个人信息
	virtual void shpwInfo();
	//获取岗位名称
	virtual string getDeptName();
	//构造函数
	Employee(int id,string name,int Did);

};