#pragma once//防止头文件重复包含
#include<iostream>
#include<string>
#define FILENAME "empFile.txt"
using namespace std;//使用标准命名空间
#include"worker.h"
#include<fstream>
class WorkerManger
{
public:
	WorkerManger();
	~WorkerManger();
	//展示菜单
	void Show_Menu();
	//退出系统
	void Exit();
	//记录职工人数
	int m_EmpNUM;
	//职工数组指针
	worker** m_EmpArray;
	//添加职工
	void Add_Emp();
	//保存文件
	void save();
	//判断文件是否为空 标志
	bool m_FileIsEmpty;
	//统计文件中人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//显示职工
	void show_Emp();
	//删除职工
	void Del_Emp();
	//判断职工是否存在
	int is_Exit(int id);
	//修改职工
	void Mod_Emp();
	//判断编号是否重复
	int panduan(int x);
	//查找
	void find();
	//排序
	void sort();
	//清空
	void clear();
};