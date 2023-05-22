//#include <iostream>
//#include<vector>
//using namespace std;
//#define N 5
//#define M 9999999 
//void tanxin(int n, int v, int dist[], int p[], int c[][N + 1])//v是源点
//{
//	bool s[N + 1];//顶点集合S
//	for (int i = 1; i <= n; i++) {
//		dist[i] = c[v][i];//从源点到顶点i的最短特殊路径长度
//		s[i] = false;
//		if (dist[i] == M) 
//		{
//			p[i] = 0;//从源点到顶点i的最短路径上千一个顶点 
//		}
//		else
//		{
//			p[i] = v;
//		}
//	}
//	dist[v] = 0;//从源点到源点的距离为0
//	s[v] = true;//s[i]为true代表该顶点已经加入到我们的结果集中
//	for (int i = 1; i < n; i++) {
//		int temp = M;
//		int u = v;//上一顶点
//		//找到具有最短特殊路径长度的顶点u
//		for (int j = 1; j <= n; j++) {
//			if ((!s[j]) && (dist[j] < temp))
//			{
//				u = j;//变为下一个顶点
//				temp = dist[j];
//			}
//		}
//		s[u] = true;//表示到该顶点的路径已经计算出
//		//更新dist值
//		for (int j = 1; j <= n; j++) 
//		{
//			if ((!s[j]) && c[u][j] < M)
//			{
//				int newdist = dist[u] + c[u][j];
//				if (newdist < dist[j]) 
//				{
//					dist[j] = newdist;
//					p[j] = u;
//				}
//			}
//		}
//	}
//}
////输出最短路径v源点，i终点 
//void Traceback(int v, int i, int p[])
//{
//	//源点等于终点，即找出全部路径
//	if (v == i) 
//	{
//		cout << i;
//		return;
//	}
//	Traceback(v, p[i], p);
//	cout << "->" << i;
//}
//int main() 
//{
//	int v = 1;//设源点为1
//	int dist[N + 1];//从源点到顶点i的最短特殊路径长度,dist[i]表示从源点到顶点i的最短路径
//	int p[N + 1]; //记录最优路径下的顶点的父子关系
//	//构造带权有向图的邻接矩阵,行和列从下标从1开始 
//	int c[N + 1][N + 1];
//	//输入带权矩阵,如果该处的值为-1表示两点之间无边
//	cout << "带权有向图的邻接矩阵为：" << endl;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> c[i][j];
//			if (c[i][j] == -1) {
//				c[i][j] = M;
//			}
//		}
//	}
//	//寻找最短路径 
//	tanxin(N, v, dist, p, c);
//	//输出
//	for (int i = 1;i < 5;i++)
//	{
//		cout << "源点1到源点"<<i+1<<"的最短路径长度为：" << dist[i+1] << endl;
//		cout << "路径为：" << endl;
//		Traceback(1, i+1, p);
//		cout << endl;
//	}
//	cout << "计211-212555-王喻杰" << endl;
//	return 0;
//}