#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class edge
{
public:
	int u, v;//u、v是两个顶点
	float quan;//quan代表两个顶点的权值
	edge(int a, int b, float c) :u(a), v(b), quan(c){};
};
bool cmp(edge a, edge b)
{
	return a.quan < b.quan;
}
//寻找结点的根节点
//如果两个顶点属于两个不同的连通块中,那么他们的根节点应该不同
int findFather(vector<int> father, int x)//返回传入顶点的根节点号
{
	int a = x;
	while (x != father[x])//传进来的x是顶点号
	{
		//如果不等于,说明此时的x不是.
		x = father[x];
	}
	//此时的x就是根节点
	 //更新father参数
	int z;
	while (a != father[a])
	{
		z = a;
		a = father[a];
		father[z] = x;//此时father记录的便是根节点
	}
	return x;
}

void Kruskal(int n, int m, vector<edge>& E, vector<edge>& res, float& totalCost)
{
	//其中n是顶点数，m是边数,E是带权矩阵,res是已经加入到最优解向量的边,totalCost是当前总的路径长度
	vector<int> father(n + 1, 0);
	for (int i = 1;i <= n;i++)
	{
		father[i] = i;
	}
	sort(E.begin(), E.end(), cmp);//按照权值从小到大排序
	for (int i = 0; i < m; ++i)
	{
		int faU = findFather(father, E[i].u);
		int faV = findFather(father, E[i].v);
		//查找u、v的根结点
		if (faU != faV)
		{
			//说明此时两个结点不在同一个连同块
			res.push_back(E[i]);//加入到结果
			father[faV] = faU;//更改根结点
			totalCost += E[i].quan;
			//            if (NumEdge == n-1) break; // 如果原图是由多个区域组成，则注释这一句
		}
	}
}
int main()
{
	//初始化边
	vector<edge> v1{ edge(1,2,6),edge(1,4,5),edge(1,3,1),edge(2,5,3),edge(3,5,6),edge(2,3,5),edge(3,6,4),edge(3,4,5),edge(4,6,2),edge(5,6,6)};
	random_shuffle(v1.begin(), v1.end());
	for (int i = 0;i < v1.size();i++)
	{
		cout << "从" << v1[i].u << "顶点" << "到" << v1[i].v << "顶点,距离是" << v1[i].quan << endl;
	}
	cout << "-------------------------------" << endl;
	int n = 6;
	int m = 10;
	vector<edge> v3;
	float sum = 0;
	Kruskal(n, m, v1, v3, sum);
	cout << "u\t" << "v\t" << "w" << endl;
	for (int i = 0;i < v3.size();i++)
	{
		cout << v3[i].u << "\t" << v3[i].v << "\t" << v3[i].quan << endl;
	}
	cout << "总和为:" << endl;
	cout << sum << endl;
	cout << "计211 王喻杰 212555" << endl;
}