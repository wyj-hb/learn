#include"WorkerManger.h"
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manger.h"
int main()
{
	//实例化管理者对象
	WorkerManger wm;
	int choice = 0;
	while (true)
	{
		//调用展示菜单函数
		wm.Show_Menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.Exit();
			break;
		case 1://增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.find();
			break;
		case 6://排序职工
			wm.sort();
			break;
		case 7://清空文档
			wm.clear();
			break;
		}

	}
	system("pause");
	return 0;
}