#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
void showmenu()
{
	cout <<"****************************"<<endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "****************************" << endl;
}
//设计联系人结构体
struct people
{
	string name;
	int sex;
	int age;
	string tele;
	string add;
};
//设计通讯录
struct book
{
	people s[MAX];
	int num;
};
//添加联系人
void addPerson(struct book *stu)
{
	//判满
	if (stu->num == MAX)
	{
		cout << "添加失败，人数已满" << endl;
		return;
	}
	else
	{
		//添加联系人
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		stu->s[stu->num].name = name;
		cout << "请输入性别";
		cout << "男——1,女——2" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				stu->s[stu->num].sex = sex;
				break;
			}
			else
			{
				cout << "抱歉您输入的有误，请重新输入" << endl;
			}
		}
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		stu->s[stu->num].age = age;
		cout << "请输入联系电话" << endl;
		string tele;
		cin >> tele;
		stu->s[stu->num].tele = tele;
		cout << "请输入地址" << endl;
		string add;
		cin >> add;
		stu->s[stu->num].add = add;
		stu->num++;
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}
//显示联系人
void showperson(book *b)
{
	//判0;
	if (b->num == 0)
	{
		cout << "记录为空" << endl;
	}
	else
	{
		for (int i = 0;i < b->num;i++)
		{
			cout << "姓名: " << b->s[i].name << "\t";
			cout << "性别: " << (b->s[i].sex == 1 ? "男":"女")<< "\t";
			cout << "年龄: " << b->s[i].age << "\t";
			cout << "电话: " << b->s[i].tele << "\t";
			cout << "住址: " << b->s[i].add <<endl;
		}
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在，存在返回索引位置，不存在返回-1
int isexist(book *b, string name)
{
	for (int i = 0;i < b->num;i++)
	{
		if (b->s[i].name == name)
		{
			return i;
		}
	}
	return -1;
}
//删除联系人
void Delete(book *b)
{
	cout << "请输入删除联系人的姓名" << endl;
	string name;
	cin >> name;
	int ret = isexist(b,name);
	if (ret != -1)
	{
		cout << "找到此人" << endl;
		for (int i = ret;i < b->num;i++)
		{
			//数据迁移
			b->s[i] = b->s[i + 1];
		}
		b->num--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
	return;
}
//查找指定的联系人
void find(book* b)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(b, name);
	if (ret != -1)
	{
		cout << "找到此人" << endl;
		cout << "姓名: " << b->s[ret].name << "\t";
		cout << "性别: " << (b->s[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄: " << b->s[ret].age << "\t";
		cout << "电话: " << b->s[ret].tele << "\t";
		cout << "住址: " << b->s[ret].add << endl;
	}
	else
	{
		cout << "未找到该联系人" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void modify(book* b)
{
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(b, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		b->s[ret].name = name;
		cout << "请输入性别";
		cout << "男——1,女——2" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				b->s[ret].sex = sex;
				break;
			}
			else
			{
				cout << "抱歉您输入的有误，请重新输入" << endl;
			}
		}
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		b->s[ret].age = age;
		cout << "请输入联系电话" << endl;
		string tele;
		cin >> tele;
		b->s[ret].tele = tele;
		cout << "请输入地址" << endl;
		string add;
		cin >> add;
		b->s[ret].add = add;
	}
	else
	{
		cout << "未找到该联系人" << endl;
	}
	system("pause");
	system("cls");

}
//清空联系人
void clean(book* b)
{
	b->num = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//创建通讯录结构体变量
	book b;
	b.num = 0;
	//退出功能
	int select = 0;
	while (true)
	{
		//菜单调用
		showmenu();
		cin >> select;
		switch(select)
		{
		case 1://1.添加联系人
			addPerson(&b);
			break;
		case 2://2.显示联系人
			showperson(&b);
			break;
		case 3://3.删除联系人
		{
			Delete(&b);
			break;
		}
		case 4://4.查找联系人
			find(&b);
			break;
		case 5://5.修改联系人
			modify(&b);
			break;
		case 6://6.清空联系人
			clean(&b);
			break;
		case 0://0.退出通讯录
			cout << "欢迎您的下次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	return 0;
}