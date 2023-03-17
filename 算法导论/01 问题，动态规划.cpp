#include<iostream>
using namespace std;
//01问题，动态规划法
void Knapsack(int n,int c, int w[], int p[]) {
	int f[10][10];
	for (int i = 0;i <= 6;i++)//六行六列
	{
		f[0][i] = 0;
		f[i][0] = 0;
	}
	int i = 0;
	int j = 0;
	for (i = 1;i <= c;i++) {
		for (j = 1;j <= n;j++) {
			f[i][j] = f[i - 1][j];
			if (j >= w[i]) {
				f[i][j] = f[i - 1][j] > (f[i - 1][j - w[i]] + p[i]) ? f[i-1][j] : (f[i - 1][j - w[i]] + p[i]);
			}
		}
	}
	//输出
	for (int x = 0;x < 6;x++)
	{
		for (int y = 0;y < 7;y++)
		{
			cout << f[x][y] << " ";
		}
		cout << endl;
	}
	cout << "背包能装的最大价值是:" << f[i-1][j-1] << endl;
}
int main() {
	int c = 5; //物体的总数目
	int n = 6;//背包容量n
	int w[6] = { 0,3,2,1,4,5 };//物重w
	int p[6] = { 0,25,20,15,40,50 };//物价p 
	Knapsack(n,c, w, p);
	return 0;
}
