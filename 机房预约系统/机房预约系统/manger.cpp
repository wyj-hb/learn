#include"manger.h"
//默认构造
manger::manger()
{

}
//有参构造 
manger::manger(string name, string pwd)
{
	this->m_name = name;
	this->m_pass = pwd;
	//初始化容器 获取到所有文件中 学生、老师信息
	this->initvector();
	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerroom com;
	while (ifs >> com.m_comid && ifs >> com.m_max)
	{
		vcom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为：" << vcom.size() << endl;
}
//菜单界面
void manger::openmenu()
{
	cout << "欢迎管理员:" << this->m_name << "登陆！" << endl;
	cout << "\t\t--------------------------------\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          1.添加账号          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          2.查看账号          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          3.查看机房          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          4.清空预约          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|          0.注销登陆          |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t-------------------------------|\n";
}
//添加账号
void manger::addperson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	int select = 0;
	cin >> select;
	string filename;//操作文件名
	string tip;//提示id号
	string errortip;
	ofstream ofs;//文件操作对象
	if (select == 1)
	{
		//添加学生
		filename = STUDENT_FILE;
		tip = "请输入学号";
		errortip = "学号重复，请重新输入";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "请输入职工号";
		errortip = "职工号重复，请重新输入";
	}
	//利用追加的方式 写文件
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkPepeat(id, select);
		if (ret)
		{
			//有重复
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" <<endl;
	system("pause");
	system("cls");
	ofs.close();
	//调用初始化容器接口
	this->initvector();
}
//查看账号
void printstu(student& s);
void printtea(teacher& t);
void manger::showperson()
{
	cout << "请选择查看内容:" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	int select = 0;//接受用户选择
	cin >> select;
	if (select == 1)
	{
		//查看学生
		cout << "所有学生信息如下" << endl;
		for_each(vstu.begin(), vstu.end(), printstu);
	}
	else
	{
		//查看老师
		cout << "所有老师信息如下" << endl;
		for_each(vtea.begin(), vtea.end(), printtea);
	}
	system("pause");
	system("cls");
}
void printtea(teacher& t)
{
	cout << "职工号：" << t.m_empod << "姓名：" << t.m_name << "密码：" << t.m_pass << endl;
}
//查看机房信息
void manger::showcpm()
{
	cout << "机房信息如下" << endl;
	for (vector<computerroom>::iterator it = vcom.begin();it != vcom.end();it++)
	{
		cout << "机房编号:" << it->m_comid << "机房最大容量：" << it->m_max << endl;
	}
	system("pause");
	system("cls");
}
//清空预约记录
void manger::clean()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}
//初始化容器
void manger::initvector()
{
	//确保容器情况状态
	vstu.clear();
	vtea.clear();
	//读取信息 学生、老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pass)
	{
		//信息存在
		vstu.push_back(s);
	}
	cout << "当前学生数量为:" << vstu.size() << endl;
	ifs.close();
	//读取信息
	ifs.open(TEACHER_FILE, ios::in);
	teacher t;
	while (ifs >>t.m_empod && ifs >> t.m_name && ifs >>t.m_pass)
	{
		//信息存在
		vtea.push_back(t);
	}
	cout << "当前老师数量为:" << vtea.size() << endl;
	ifs.close();
}
void printstu(student& s)
{
	cout << "学号：" << s.m_id << "姓名：" << s.m_name << "密码：" << s.m_pass << endl;
}
//检测重复 参数1 检测学号/职工号 参数2 检测类型
bool  manger::checkPepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
		for (vector<student>::iterator it = vstu.begin();it != vstu.end();it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		//检测老师
		for (vector<teacher>::iterator it = vtea.begin();it != vtea.end();it++)
		{
			if (id == it->m_empod)
			{
				return true;
			}
		}

	}
	return false;
}