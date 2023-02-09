#pragma once//防止头文件重复编译
#include<iostream>
using namespace std;
class speaker
{
public:
	string m_name;
	double m_score[2];//最多有两轮的成绩
};