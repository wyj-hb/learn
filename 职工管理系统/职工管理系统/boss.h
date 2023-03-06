#include"worker.h"
class boss :public worker
{
public:
	//显示个人信息
	virtual void shpwInfo();
	//获取岗位名称
	virtual string getDeptName();
	boss(int id, string ame, int Did);
};