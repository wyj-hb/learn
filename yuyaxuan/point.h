#pragma once
#include<iostream>
using namespace std;
// µ„¿‡
class Point
{
public:
	void setx(int x);
	
	int getx();
	
	void sety(int y);
	
	int gety();
	
private:
	int p_x;
	int p_y;
};