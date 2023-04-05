//#include<iostream>
//#include<vector>
//using namespace std;
///*最近点对问题*/
//#include<stdlib.h>
//#include<iostream>
//#include<algorithm>
//#include<math.h>
//#include<ctime>
//using namespace std;
////坐标(x,y)
//struct node {
//	int x;
//	int y;
//};
//
////生成随机点
//void creatpoint(node s[], int num)
//{
//	/*srand((unsigned)time(NULL));*/
//	for (int i = 0;i < num;i++)
//	{
//		s[i].x = rand() % 1000;
//		s[i].y = rand() % 1000;
//	}
//	cout << "随机点对生成成功" << endl;
//	/*for (int i = 0;i < num;i++)
//	{
//		cout << "(" << s[i].x << "," << s[i].y << ")  ";
//	}*/
//	cout << endl;
//}
//
////求解距离
//double distances(node a, node b)
//{
//	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));//sqrt用来求解平方根
//}
//
///*按坐标升序排列*/
//bool cmpx(node& a, node& b)
//{
//	return a.x < b.x;
//}
//
///*按y坐标升序排列*/
//bool cmpy(node& a, node& b)
//{
//	return a.y < b.y;
//}
//
////分治法
//double fenzhi(node s[], int low, int high)
//{
//
//	double d1, d2, d3, d;
//	int mid, i, j, index;
//	node p[101];//总点集
//	node minp1, minp2;
//	if (high - low == 1)
//	{
//		return distances(s[low], s[high]);
//	}
//	if (high - low == 2)
//	{
//		d1 = distances(s[low], s[low + 1]);
//		d2 = distances(s[low + 1], s[high]);
//		d3 = distances(s[low], s[high]);
//		if ((d1 < d2) && (d1 < d3))
//			return d1;
//		else if (d2 < d3) return d2;
//		else return d3;
//	}
//	mid = (low + high) / 2;//计算中间点
//	d1 = fenzhi(s, low, mid);//递归求解左
//	d2 = fenzhi(s, mid + 1, high);//递归求解右
//	if (d1 < d2) d = d1;
//	else d = d2;
//	index = 0;
//	for (i = mid;(i >= low) && (s[mid].x - s[i].x < d);i--)//建立p1 
//	{
//		p[index++] = s[i];
//	}
//	for (i = mid + 1;(i <= high) && (s[i].x - s[mid].x < d);i++)//建立p2 
//	{
//		p[index++] = s[i];
//	}
//	sort(p, p + index, cmpy);//对集合p1和p2按y坐标升序排列 
//	for (i = 0;i < index;i++)
//	{
//		for (j = i + 1;j < index;j++)
//		{
//			if (p[j].y - p[i].y >= d)
//				break;
//			else {
//				d3 = distances(p[i], p[j]);
//				if (d3 < d)
//				{
//					d = d3;
//					minp1 = p[i];
//					minp2 = p[j];
//				}
//			}
//		}
//		return d;
//	}
//
//}
//
///*蛮力法解决*/
//void force(node p[], int length)
//{
//	int i, j;
//	double min, temp;
//
//	node minp1 = p[0];
//	node minp2 = p[1];
//
//	min = distances(p[0], p[1]);
//	for (i = 0;i < length - 1;i++)
//	{
//		for (j = i + 1;j < length;j++)
//		{
//			temp = distances(p[i], p[j]);
//			if (temp < min) {
//				min = temp;
//				minp1 = p[i];
//				minp2 = p[j];
//			}
//		}
//	}
//	cout << endl;
//	cout << endl;
//	cout << "最近点对为" << endl;
//	cout << "(" << minp1.x << ")" << "(" << minp1.y << ")和" << "(" << minp2.x << ")" << "(" << minp2.y << ")" << endl;
//	cout << "******" << endl;
//	cout << "蛮力法" << endl;
//	cout << "******" << endl;
//	cout << "最近距离为: " << min << endl;
//	cout << endl;
//}
//int main()
//{
//	node s[1001];
//	creatpoint(s, 1000);//随机生成100个点
//
//	//蛮力法解决
//	time_t b1, e1;
//	double t1;
//	b1 = clock();
//
//	force(s, 1000);
//
//	int m = 10000000;
//	while (m)
//	{
//		m--;
//	}
//	e1 = clock();
//	t1 = double(e1 - b1);
//
//	cout << "运行时间 " << t1 << "ms" << endl;
//	//分治法 
//	time_t b2, e2;
//	double t2;
//	b2 = clock();
//	cout << "******" << endl;
//	cout << "分治法" << endl;
//	cout << "******" << endl;
//	double n;
//	sort(s, s + 1000, cmpx);//按x升序将点集排列 
//	 n = fenzhi(s, 0, 1000);
//	cout << "最近距离为 " << endl;
//	cout << n << endl;
//	int k = 10000000;
//	while (k)
//	{
//		k--;
//	}
//	e2 = clock();
//	t2 = double(e2 - b2);
//	cout << "运行时间 " << t2 << "ms" << endl;
//	cout << "计211" << " " << "王喻杰" << " " << "212555" << endl;
//	return 0;
//}