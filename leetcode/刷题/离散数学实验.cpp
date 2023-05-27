//#include<iostream>
//#include<vector>
//using namespace std;
//int luojijia(int a, int b)
//{
//	if (a == 1 || b == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//void xiangjia(vector<vector<int>> &v, int m, int n)
//{
//	//将第m行逻辑加到第n行
//	for (int i = 0;i<v.size();i++)
//	{
//		v[n][i] = luojijia(v[m][i], v[n][i]);
//	}
//}
//void t(vector<vector<int>> &v)
//{
//	for (int i = 0;i < v.size();i++)
//	{
//		for (int j = 0;j < v.size();j++)
//		{
//			if (v[j][i] == 1)
//			{
//				//将第i行加到第j行
//				xiangjia(v, i, j);
//			}
//		}
//	}
//}
//void panduan(vector<vector<int>> v1)
//{
//	int size = v1.size();
//	//判断是否是自反的
//	bool op = true;
//	cout << "-------------------------" << endl;
//	for (int i = 0;i < v1.size();i++)
//	{
//		if (v1[i][i] == 0)
//		{
//			cout << "不是自反的" << endl;
//			op = false;
//			break;
//		}
//	}
//	if (op)
//	{
//		cout << "是自反的" << endl;
//	}
//	cout << "-------------------------" << endl;
//	op = true;
//	for (int i = 0;i < v1.size();i++)
//	{
//		if (v1[i][i] == 1)
//		{
//			cout << "不是反自反的" << endl;
//			op = false;
//			break;
//		}
//	}
//	if (op)
//	{
//		cout << "是反自反的" << endl;
//	}
//	cout << "-------------------------" << endl;
//	op = true;
//	for (int i = 0;i < v1.size();i++)
//	{
//		for (int j = i + 1;j < v1.size();j++)
//		{
//			if (v1[i][j] != v1[j][i])
//			{
//				cout << "不是对称的" << endl;
//				op = false;
//				break;
//			}
//		}
//		if (op == false)
//		{
//			break;
//		}
//	}
//	if (op)
//	{
//		cout << "是对称的" << endl;
//	}
//	cout << "-------------------------" << endl;
//	op = true;
//	for (int i = 0;i < v1.size();i++)
//	{
//		for (int j = 0;j < v1.size();j++)
//		{
//			if (v1[i][j] == v1[j][i] &&v1[i][j] == 1 && i != j)
//			{
//				cout << "不是反对称的" << endl;
//				op = false;
//				break;
//			}
//		}
//		if (op == false)
//		{
//			break;
//		}
//	}
//	if (op)
//	{
//		cout << "是反对称的" << endl;
//	}
//	cout << "-------------------------" << endl;
//	vector<vector<int>> v2 = v1;
//	t(v2);
//	if (v2 == v1)
//	{
//		cout << "是传递的" << endl;
//	}
//	else
//	{
//		cout << "不是传递的" << endl;
//	}
//	cout << "-------------------------" << endl;
//}
//void printf(vector<vector<int>> v)
//{
//	for (int i = 0;i < v.size();i++)
//	{
//		for (auto z : v[i])
//		{
//			cout << z << " ";
//		}
//		cout << endl;
//	}
//}
//int main()
//{
//	int n;
//	cout << "请输入关系矩阵的行数(列数)" << endl;
//	cin >> n;
//	vector<int> v(n, 0);
//	vector<vector<int>> v1(n, v);
//	cout << "请输入关系矩阵" << endl;
//	int x;
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0;j < n;j++)
//		{
//			cin >> x;
//			v1[i][j] = x;
//		}
//	}
//	/*printf(v1);*/
//	panduan(v1);
//}