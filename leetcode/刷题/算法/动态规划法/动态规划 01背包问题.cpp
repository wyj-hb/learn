#include<iostream>
#include<vector>
using namespace std;

void shuchu(vector<vector<int>> v)
{
	for (int i = 0;i < v.size();i++)
	{
		for (int j = 0;j < v[0].size();j++)
		{
			cout << v[i][j] << "\t";
		}
		cout << endl;
	}
}
void shuchu2(vector<int> v)
{
	string s = "";
	for (int i = 1 ;i<v.size();i++)
	{
		cout << "x" << i << "=" << v[i] << " ";
	}
	cout << endl;
}
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
void KnapSack(vector<int> w, vector<int> v,vector<vector<int>> &v3,vector<int> &v4)//w是重量,v是价值,v3是结果容器,v4用来存放结果
{
	int n = v3.size()-1;//行
	int c = v3[0].size()-1;//列
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= c;j++)
		{
 			if (j < w[i-1])//重量不足以方第i个物品
			{
				v3[i][j] = v3[i - 1][j];
			}
			else
			{
				v3[i][j] = max(v3[i - 1][j], v3[i - 1][j - w[i-1]] + v[i-1]);
			}
		}
	}
	int j = c;
	for (int i = n; i > 0; i--)
	{
		if (v3[i][j] > v3[i - 1][j]) 
		{
			v4[i] = 1;
			j = j - w[i-1];
		}
		else v4[i] = 0;
	}
}
int main()
{
	int a;
	cout << "请输入背包容量" << endl;
	cin >> a;
	vector<int> v1(a+1, 0);
	cout << "请输入物品数量" << endl;
	cin >> a;
	int x = a;
	vector<vector<int>> v2(a+1, v1);
	vector<int> v3;
	cout << "请输入各物品重量" << endl;
	for (int i = 0;i < x;i++)
	{
		cin >> a;
		v3.push_back(a);
	}
	vector<int> v4;
	cout << "请输入各物品价值" << endl;
	for (int i = 0;i < x;i++)
	{
		cin >> a;
		v4.push_back(a);
	}
	vector<int> v5(x+1,0);
	KnapSack(v3, v4, v2, v5);
	cout << "表格为" << endl;
	shuchu(v2);
	cout << "向量解为" << endl;
	shuchu2(v5);
	cout << "最大值为" << endl;
	int n = v2.size() - 1;//行
	int c = v2[0].size() - 1;//列
	cout << v2[n][c] << endl;
	cout << "计211-212555-王喻杰" << endl;
}
