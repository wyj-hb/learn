//#include<iostream>
//#include<vector>
//using namespace std;
////vector<int> lujing;
////vector<int> nowlujing;
////vector<vector<int>> v9;
////int max1 = 0;
////int nowwight = 0;
////int nowmax = 0;
////01背包问题
////void jiance(vector<int> v)
////{
////	for (int i = 0;i<v.size();i++)
////	{
////		cout <<"放入的第"<<i+1<<"个物品价值是:" <<v[i] <<endl;
////	}
////	cout << endl;
////}
////void backtracing(vector<int> v1, vector<int> v2, int num, int capacity,int startindex)//v1是价值，v2是重量
////{
////	if (nowwight > capacity)
////	{
////		cout << endl;
////		cout << "放入第" << startindex << "个物品使得放入的物品总容量大于背包容量,进行剪枝" << endl;
////		return;
////	}
////	if (nowmax > max1)
////	{
////		lujing = nowlujing;
////		max1 = nowmax;
////	}
////	for (int i = startindex;i < num;i++)
////	{
////		nowmax += v1[i];
////		nowwight += v2[i];
////		nowlujing.push_back(v1[i]);
////		cout << "放入第" << i + 1 << "个物品 ";
////		backtracing(v1, v2, num, capacity, i+1);
////		cout << "取出第" << i + 1 << "个物品" << endl;
////		cout << "----------------------------" << endl;
////		nowlujing.pop_back();
////		nowmax -= v1[i];
////		nowwight -= v2[i];
////	}
////	return;
////}
////int main()
////{
////	int num;
////	int capacity;
////	cout << "请输入物品数量" << endl;
////	cin >> num;
////	cout << "请输入各物品的价值" << endl;
////	vector<int> v1;
////	int x = 0;
////	for (int i = 0;i < num;i++)
////	{
////		cin >> x;
////		v1.push_back(x);
////	}
////	vector<int> v2;
////	cout << "请输入各物品的重量" << endl;
////	for(int i = 0;i<num;i++)
////	{
////		cin >> x;
////		v2.push_back(x);
////	}
////	cout << "请输入背包容量" << endl;
////	cin >> capacity;
////	backtracing(v1, v2, num, capacity, 0);
////	jiance(lujing);
////	cout << "最大值为" << max1 << endl;
////	cout << "计211-212555-王喻杰" << endl;
////	cout << endl;
////}
////tsp问题
//int count1 = 1;//记录当前加入的城市数量
//int min1 = INT_MAX;
//int nowlength = 0;
//vector<int> lujing;
//vector<int> nowlujing;
//int length = INT_MAX;
//void clear(vector<int> &v)
//{
//	int x = v.size();
//	for (int i = 0;i < x;i++)
//	{
//		v.pop_back();
//	}
//}
//vector<vector<int>> v9;
//vector<int> v10;
//void backtrace(vector<vector<int>> v,int dingdian,int dangqian,vector<int>& used)
//{
//	if (nowlength > min1 && min1!= INT_MAX)
//	{
//		cout << "不符合条件,进行剪枝"<< endl;
//		return;
//	}
//	if (count1 == v.size())
//	{
//		//此时所有城市均遍历,应当返回出发点
//		nowlength += v[dangqian][dingdian];
//		nowlujing.push_back(dingdian);
//		cout << "此时是一条可行路径" << endl;
//		if (nowlength < min1)
//		{
//			min1 = nowlength;
//			lujing = nowlujing;
//		}
//		v9.push_back(nowlujing);
//		v10.push_back(nowlength);
//		nowlujing.pop_back();
//		nowlength -= v[dangqian][dingdian];
//		return;
//	}
//	for (int i = 0;i < v.size();i++)
//	{
//		int x = dangqian;
//		if (used[i] == 1)
//		{
//			continue;
//		}
//		nowlength += v[dangqian][i];
//		count1++;
//		dangqian = i;
//		used[i] = 1;
//		nowlujing.push_back(i);
//		cout << "加入顶点" << i + 1 << " ";
//		backtrace(v, dingdian, dangqian, used);
//		cout << "去除顶点" << i + 1 << " ";
//		dangqian = x;
//		nowlength -= v[dangqian][i];
//		nowlujing.pop_back();
//		count1--;
//		used[i] = 0;
//	}
//}
//void lujing1(vector<int> v)
//{
//	for (int i = 0;i < v.size();i++)
//	{
//		if (i != v.size() - 1)
//		{
//			cout << v[i] + 1 << "->";
//		}
//		else
//		{
//			cout << v[i] + 1;
//		}
//	}
//	cout << endl;
//}
//void lujing2(vector<vector<int>> v, vector<int> v1)
//{
//	for (int i = 0;i < v.size();i++)
//	{
//		cout << "第" << i + 1 << "条路径为" << endl;
//		for (int j = 0;j < v[i].size();j++)
//		{
//			if (j != v[i].size() - 1)
//			{
//				cout << v[i][j] + 1 << "->";
//			}
//			else
//			{
//				cout << v[i][j] + 1;
//			}
//		}
//		cout << endl;
//		cout << "长度为" << v1[i] << endl;
//	}
//	cout << endl;
//}
//void zhiling(vector<int> &v)
//{
//	int x = v.size();
//	for (int i = 0;i<x;i++)
//	{
//		v[i] = 0;
//	}
//}
//int main()
//{
//	int num;
//	cout << "请输入城市个数" << endl;
//	cin >> num;
//	vector<int> v1(num, 0);
//	int x = 0;
//	vector<vector<int>> v2(num, v1);//邻接矩阵
//	cout << "请输入邻接矩阵" << endl;
//	for (int i = 0;i < num;i++)
//	{
//		for (int j = 0;j < num;j++)
//		{
//			cin >> x;
//			v2[i][j] = x;
//		}
//	}
//	vector<int> used(num, 0);
//	for (int i = 0;i < num;i++)
//	{
//		nowlujing.push_back(i);
//		used[i] = 1;//代表已经选择
//		cout << "从顶点" << i + 1 << "出发" << endl;
//		backtrace(v2, i,i,used);
//		cout << endl;
//		cout << "最短路径是" << endl;
//		lujing1(lujing);
//		cout << "最短路径长度为" << min1 << endl;
//		count1 = 1;
//		min1 = INT_MAX;
//		nowlength = 0;
//		clear(lujing);
//		clear(nowlujing);
//		zhiling(used);
//	}
//	cout << "计211-212555-王喻杰 " << endl;
//}