#include<iostream>
#include<fstream>
using namespace std;
#include"identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manger.h"
//登录功能
void mangerMenu(Idenity*& m);
void studentMenu(Idenity*& s);
void teacherMenu(Idenity*& t);
void Login(string filename,int type)
{
	//父类指针，用来指向子类对象
	Idenity* person = NULL;
	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);
	//判断文件是否存在
	if (!ifs)
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备用户信息
	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if(type == 2)
	{
		cout << "请输入您的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码"<<endl;
	cin >> pwd;
	if (type == 1)
	{
		//学生信息验证
		int fid;//从文件中读取的id号码
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >>fpwd)
		{
			//与用户信息做对比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new student(id,name,pwd);
				//进入学生身份子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师信息验证
		int fid;//从文件中读取的id号码
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//与用户信息做对比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "教师验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, pwd);
				//进入教师身份子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员信息验证
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			//与用户信息做对比
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new manger(name, pwd);
				//进入管理员身份子菜单
				mangerMenu(person);
				return;
			}
		}
	}
	cout << "登陆验证失败" << endl;
	system("pause");
	system("cls");
	return;
}
//进入管理员子类菜单界面
void mangerMenu(Idenity*& m)
{
	while (true)
	{
		//多态
		//调用管理员子菜单
		m->openmenu();
		//将父类指针转为子类指针，调用子类的其他接口
		manger *man = (manger*)m;
		int select = 0;
		//接受用户选项
		cout << "请输入您的选择" << endl;
		cin >> select;
		if (select == 1)
		{
			cout << "添加账号" << endl;
			//添加账号
			man->addperson();

		}
		else if(select == 2)
		{
			cout << "查看账号" << endl;
			//查看账号
			man->showperson();
		}
		else if(select == 3)
		{
			cout << "查看机房" << endl;
			//查看机房
			man->showcpm();
		}
		else if (select == 4)
		{
			//清空预约
			man->clean();
		}
		else
		{
			delete man;//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//进入学生子菜单界面
//进入管理员子类菜单界面
void studentMenu(Idenity*& s)
{
	while (true)
	{
		//多态
		//调用管理员子菜单
		s->openmenu();
		//将父类指针转为子类指针，调用子类的其他接口
		student* stu = (student*)s;
		int select = 0;
		//接受用户选项
		cout << "请输入您的选择" << endl;
		cin >> select;
		if (select == 1)//申请预约
		{
			stu->applyorder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showmyorder();
		}
		else if (select == 3)//查看所有人信息
		{
			stu->lookorder();
		}
		else if (select == 4)//取消预约
		{
			stu->quxiao();
		}
		else
		{
			//注销登陆
			delete stu;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//进入教师子菜单界面
void teacherMenu(Idenity*& t)
{
	while (true)
	{
		t->openmenu();
		teacher* tea = (teacher*) t;
		int select = 0;//接受用户选择
		cout << "请输入您的选择" << endl;
		cin >> select;
		if (select == 1)//查看所有预约
		{
			tea->lookorder();
		}
		else if (select == 2)
		{
			tea->validmyorder();
		}
		else
		{
			delete tea;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
		}
	}
}
int main()
{
	int select = 0;
	while (true)
	{
		cout << "=========欢迎来到传智播客机房预约系统========" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t-----------------------------\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|          1.学生代表        |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|          2.老     师       |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|          3.管  理   员     |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|          0.退      出      |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t-----------------------------\n";
		cout << "请输出您的选择" << endl;
		cin >> select;
		switch (select)
		{
		case 1://学生
			Login(STUDENT_FILE, 1);
			break;
		case 2://老师
			Login(TEACHER_FILE, 2);
			break;
		case 3://管理员
			Login(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎您下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}