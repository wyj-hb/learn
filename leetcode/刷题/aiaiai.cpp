//#include<iostream>
//#include<vector>
//using namespace std;
//double pingjun(vector<double> v)
//{
//	double sum = 0;
//	int size = v.size();
//	for (int i = 0;i < size;i++)
//	{
//		sum += v[i];
//	}
//	return sum / size-1;
//}
//double fangcha(double a, vector<double> v)
//{
//	double sum = 0;
//	int size = v.size();
//	for (int i = 0;i < size;i++)
//	{
//		sum += (v[i] - a) * (v[i] - a);
//	}
//	return sum / size;
//}
//int main()
//{
//	cout << "请输入数组大小" << endl;
//	int n;
//	cin >> n;
//	vector<double> v1;
//	double x = 0;
//	cout << "请输入各元素的值" << endl;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> x;
//		v1.push_back(x);
//	}
//	double a = pingjun(v1);
//	double g = fangcha(a,v1);
//	cout << g << endl;
//}