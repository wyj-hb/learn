#include"teacher.h"
//默认构造
teacher::teacher()
{
	
}
//有参构造 
teacher::teacher(int empid, string name, string pwd)
{
	//初始化属性
	this->m_empod = empid;
	this->m_name = name;
	this->m_pass = pwd;
}
//审核预约
void teacher::validmyorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>v;
	int index = 0;
	cout << "待审核的预约记录如下:" << endl;
	for (int i = 0;i < of.m_size;i++)
	{
		if (of.m_order[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、";
			cout << "预约日期：周" << of.m_order[i]["data"];
			cout << "时间段：" << (of.m_order[i]["interval"] == "1" ? "上午" : "下午");
			cout << "学生学号：" << of.m_order[i]["stuId"];
			cout << "学生姓名：" << of.m_order[i]["stuName"];
			cout << "机房号：" << of.m_order[i]["roomId"];
			string status = "状态:审核中";
			cout << status << endl;
		}
	}
	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select = 0;//接受用户选择的预约记录
	int ret = 0;//接受预约记录结果
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果:"<<endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//通过情况
					of.m_order[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_order[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
//查看所有预约
void teacher::lookorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_size;i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_order[i]["data"];
		cout << "时间段：" << (of.m_order[i]["int"] == "1" ? "上午" : "下午");
		cout << "学号：" << of.m_order[i]["stuId"];
		cout << "姓名：" << of.m_order[i]["stuName"];
		cout << "机房号：" << of.m_order[i]["roomId"];
		string status = "状态：";
		//1 审核中 2 已预约 -1 预约失败 0 取消预约
		if (of.m_order[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_order[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_order[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//菜单界面
void teacher::openmenu()
{
	cout << "欢迎老师:" << this->m_name << "登陆！" << endl;
	cout << "\t\t--------------------------------\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          1.查看所有预约      |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          2.审核预约          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          0.注销登陆          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t-------------------------------|\n";
}