#include"WorkerManger.h"
#include"employee.h"
#include"boss.h"
#include"manger.h"
WorkerManger::WorkerManger()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		/*cout << "文件不存在" << endl;*/
		//初始化属性
		this->m_EmpArray = NULL;
		this->m_EmpNUM = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		/*cout << "文件为空!" << endl;*/
		//初始化记录人数
		this->m_EmpNUM = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在，并且记录数据
	int num = this->get_EmpNum();
	/*cout << "职工人数为:" << num << endl;*/
	this->m_EmpNUM = num;
	//开辟空间
	this->m_EmpArray = new worker * [this->m_EmpNUM];
	//将文件中的数据存到数组中
	this->init_Emp();
	/*for (int i = 0;i < this->m_EmpNUM;i++)
	{
		cout << "职工编号:  " << this->m_EmpArray[i]->m_id
			<< "姓名:  " << this->m_EmpArray[i]->name
			<< "部门编号  " << this->m_EmpArray[i]->m_Did << endl;
	}*/
}
void WorkerManger::Show_Menu()
{
	cout << "*****************************" << endl;
	cout << "****欢迎使用职工管理系统!****" << endl;
	cout << "******* 0.退出管理系统********" << endl;
	cout << "******* 1.增加职工信息********" << endl;
	cout << "******* 2.显示职工信息********" << endl;
	cout << "******* 3.删除离职职工********" << endl;
	cout << "******* 4.修改职工信息********" << endl;
	cout << "******* 5.查找职工信息********" << endl;
	cout << "******* 6.按照编号排序********" << endl;
	cout << "******* 7.清空所有文档********" << endl;
	cout << "******************************" << endl;
	cout << endl;
}
//退出系统
void WorkerManger::Exit()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序 系统函数
}
WorkerManger::~WorkerManger()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
void WorkerManger::Add_Emp()
{
	cout << "请输入添加职工的数量" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNUM + addNum;
		//开辟新空间
		worker** newSpace = new worker * [newSize];
		//将原来空间下的数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i < this->m_EmpNUM;i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0;i < addNum;i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			
			while (true)
			{
				cin >> id;
				if (this->panduan(id) != -1)
				{
					break;
				}
				else
				{
					cout << "您输入的编号重复,请重新输入" << endl;
				}
			}
			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工岗位: " << endl;
			cout << "***1. 普通职工***" << endl;
			cout << "***2.   经理  ***" << endl;
			cout << "***3.   老板  ***" << endl;
			while (true)
			{
				cin >> dSelect;
				if (dSelect > 0 && dSelect < 4)
				{
					break;
				}
				else
				{
					cout << "您输入格式有误,请重新输入" << endl;
				}
			}
			worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new manger(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNUM + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNUM = newSize;
		//更新职工不为空标志
		this->m_FileIsEmpty = false;
		//提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;
		this->save();//数据保存
	}
	else
	{
		cout << "输入错误" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManger::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);//用输出的方式打开文件 —— 写文件
	//将每个人数据写入到文件中
	for (int i = 0;i < this->m_EmpNUM;i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->name << " "
			<< this->m_EmpArray[i]->m_Did << endl;
	}
	cout << m_EmpNUM << endl;
	//关闭文件
	ofs.close();
}
int WorkerManger::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件 读
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//统计人数变量
		num++;
	}
	return num;
}
void WorkerManger::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker* worker = NULL;
		
		if (dId == 1)//普通职工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new manger(id, name, dId);
		}
		else//老板
		{
			worker = new boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkerManger::show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		for (int i = 0;i < m_EmpNUM;i++)
		{
			this->m_EmpArray[i]->shpwInfo();
		}
	}
	system("pause");
	system("cls");
}
int WorkerManger::is_Exit(int id)
{
	int index = -1;
	for (int i = 0;i < this->m_EmpNUM;i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManger::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		//按照编号删除
		cout << "请输入要删除的成员编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->is_Exit(id);
		//判断要删除的成员是否存在
		if (index != -1)
		{
			for (int i = index;i < this->m_EmpNUM - 1;i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNUM--;
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该成员" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManger::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		//按照编号修改
		cout << "请输入要修改的成员编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->is_Exit(id);
		//判断要删除的成员是否存在
		if (index != -1)
		{
			delete this->m_EmpArray[index];
			int newId = 0;
			string newname;
			int dSelect;
			cout << "查到" << id << "号职工,请输入新职工号:" << endl;
			cin >> newId;
			cout << "请输入新姓名" << endl;
			cin >> newname;
			cout << "请输入该职工岗位: " << endl;
			cout << "***1. 普通职工***" << endl;
			cout << "***2.   经理  ***" << endl;
			cout << "***3.   老板  ***" << endl;
			while (true)
			{
				cin >> dSelect;
				if (dSelect > 0 && dSelect < 4)
				{
					break;
				}
				else
				{
					cout << "您输入格式有误,请重新输入" << endl;
				}
			}
			worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newname, 1);
				break;
			case 2:
				worker = new manger(newId, newname, 2);
				break;
			case 3:
				worker = new boss(newId, newname, 3);
				break;
			default:
				break;
			}
			//更新数据
			this->m_EmpArray[index] = worker;
			cout << "更改成功!" << endl;
			this->save();
		}
		else
		{
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
int WorkerManger::panduan(int x)
{
	int index = 0;
	if (this->m_FileIsEmpty)
	{
		return index;
	}
	for (int i = 0;i < this->m_EmpNUM;i++)
	{
		if (this->m_EmpArray[i]->m_id == x)
		{
			return -1;
		}
	}
	return index;
}
void WorkerManger::find()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout<<"请选择查找方式"<< endl;
		cout<<"1.按职工编号查"<< endl;
		cout << "2.按职工姓名查" << endl;
		int x = 0;
		cin >> x;
		if (x == 1)
		{
			//按照编号查找
			cout << "请输入要查找的成员编号" << endl;
			int id = 0;
			cin >> id;
			int index = this->is_Exit(id);
			if (index != -1)
			{
				//找到职工
				cout << "查找成功！该职员信息如下" << endl;
				this->m_EmpArray[index]->shpwInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (x == 2)
		{
			//按照姓名查找
			cout << "请输入要查找的成员姓名" << endl;
			string name;
			cin >> name;
			int x = 0;
			for (int i = 0;i < this->m_EmpNUM;i++)
			{
				if (this->m_EmpArray[i]->name == name)
				{
					cout << "查找成功,职员编号为" << this->m_EmpArray[i]->m_id
						<< "其信息如下" << endl;
					this->m_EmpArray[i]->shpwInfo();
					x = 1;
				}
			}
			if (x==0)
			{
				cout << "未找到该员工" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
void WorkerManger::sort()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "  请选择排序方式 " << endl;
		cout << "1.按职工工号升序 " << endl;
		cout << "2.按职工工号降序 " << endl;
		int x = 0;
		cin >> x;
		worker* temp = NULL;
		if (x == 1)
		{
			//按照升序
			for (int i = 0;i < this->m_EmpNUM;i++)
			{
				int min = i;//假设最小值下标
				for (int j = i;j < this->m_EmpNUM;j++)
				{
					if (this->m_EmpArray[min]->m_id > this->m_EmpArray[j]->m_id)
					{
						min = j;
					}
				}
				temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[min];
				this->m_EmpArray[min] = temp;
			}
		}
		else if (x == 2)
		{
			//按照降序
			for (int i = 0;i < this->m_EmpNUM;i++)
			{
				int max = i;//假设最大值下标
				for (int j = i;j < this->m_EmpNUM;j++)
				{
					if (this->m_EmpArray[max]->m_id < this->m_EmpArray[j]->m_id)
					{
						max = j;
					}
				}
				temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[max];
				this->m_EmpArray[max] = temp;
			}
		}
		else
		{
			cout << "您的输入有误,请重新输入" << endl;
		}
		this->save();
		cout << "排序成功" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManger::clear()
{
	cout << "确定清空" << endl;
	cout << "1.确定 " << endl;
	cout << "2.返回 " << endl;
	int x = 0;
	cin >> x;
	if (x == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0;i < this->m_EmpNUM;i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNUM = 0;
		this->m_FileIsEmpty = true;
		cout << "清除成功" << endl;
		system("pause");
		system("cls");
	}
	else if (x == 2)
	{
		cout << "程序结束" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "你的输入有误,功能结束" << endl;
		system("pause");
		system("cls");
	}
}