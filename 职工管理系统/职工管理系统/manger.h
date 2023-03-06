#include"worker.h"
class manger :public worker
{
public:
	//显示个人信息
	virtual void shpwInfo();
	//获取岗位名称
	virtual string getDeptName();
	//构造函数
	manger(int id, string name, int Did);
};