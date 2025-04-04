#include"student.h"
//默认构造
student::student()
{

}
//有参构造 
student::student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pass = pwd;
	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerroom com;
	while (ifs >> com.m_comid && ifs >> com.m_max)
	{
		//将读取的信息放入到容器中
		vcom.push_back(com);
	}
	ifs.close();
}
//菜单界面
void student::openmenu()
{
	cout << "欢迎学生:" << this->m_name << "登陆！" << endl;
	cout << "\t\t--------------------------------\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          1.申请预约          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          2.查看我的预约      |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          3.查看所有预约      |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          4.取消预约          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          0.注销登陆          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t-------------------------------|\n";
}
//申请预约
void student::applyorder()
{
	cout << "机房开放时间为周一到周五!" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	int date = 0;//日期
	int interval = 0;//时间段
	int room = 0;//机房编号
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请输入申请预约的时间" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	cout << "请选择机房：" << endl;
	for (int i = 0;i < vcom.size();i++)
	{
		cout << vcom[i].m_comid << "号机房容量为：" << vcom[i].m_max << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "预约成功！审核中" << endl;
	//信息写入'
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "data:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
	return;
}
//查看自身预约
void student::showmyorder()
{
	OrderFile od;
	if (od.m_size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < od.m_size;i++)
	{
		//string 转为 int
		//string 利用 .c_str() 转 const char*
		//利用atoi (const char*) 转 int 
		if (this->m_id == atoi(od.m_order[i]["stuId"].c_str()))
		{
			cout << "预约日期：周" << od.m_order[i]["data"];
			cout << "时间段：" << (od.m_order[i]["int"] == "1" ? "上午" : "下午");
			cout << "机房号：" << od.m_order[i]["roomId"];
			string status = "状态：";
			//1 审核中 2 已预约 -1 预约失败 0 取消预约
			if (od.m_order[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (od.m_order[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (od.m_order[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}
//查看所有预约
void student::lookorder()
{
	OrderFile od;
	if (od.m_size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < od.m_size;i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << od.m_order[i]["data"];
		cout << "时间段：" << (od.m_order[i]["int"] == "1" ? "上午" : "下午");
		cout << "学号：" << od.m_order[i]["stuId"];
		cout << "姓名：" << od.m_order[i]["stuName"];
		cout << "机房号：" << od.m_order[i]["roomId"];
		string status = "状态：";
		//1 审核中 2 已预约 -1 预约失败 0 取消预约
		if (od.m_order[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (od.m_order[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (od.m_order[i]["status"] == "-1")
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
//取消预约
void student::quxiao()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	int index = 1;
	vector<int>v;//存放在最大容器中的下标编号
	for (int i = 0;i < of.m_size;i++)
	{
		//先判断是自身学号
		if (this->m_id == atoi(of.m_order[i]["stuId"].c_str()))
		{
			//再筛选状态，审核中或预约成功
			if (of.m_order[i]["status"] == "1" || of.m_order[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << of.m_order[i]["data"];
				cout << "时间段：" << (of.m_order[i]["interval"] == "1" ? "上午" : "下午");
				cout << "机房编号：" << of.m_order[i]["roomId"];
				string status;
				if (of.m_order[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_order[i]["status"] == "1")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;
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
				of.m_order[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}