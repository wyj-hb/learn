#include<iostream>
using namespace std;
//void bin_search(int data[], int val,int size)//val是我们要查找的元素,size是数组的大小
//{
//	int low = 0;
//	int high = size - 1;
//	while (low <= high && val != -1)
//	{
//		int mid = (high + low) / 2;
//		if (val > data[mid])
//		{
//			//此时说明数据在mid位置的右边
//			low = mid + 1;
//		}
//		else if (val < data[mid])
//		{
//			//此时说明在mid位置的左边
//			high = mid - 1;
//		}
//		else
//		{
//			//此时找到我们想要的元素
//			cout << "找到了,元素为" <<data[mid]<< endl;
//			return;
//		}
//	}
//	cout << "可惜没有找到" << endl;
//}
void bin_search(int data[], int val,int size)//改进版，插入排序法
{
	int low = 0;
	int high = size - 1;
	while (low <= high && val != -1)
	{
		int mid = low + (high - low) * (val - data[low]) / (data[high] - data[low]);
		if (val > data[mid])
		{
			//此时说明数据在mid位置的右边
			low = mid + 1;
		}
		else if (val < data[mid])
		{
			//此时说明在mid位置的左边
			high = mid - 1;
		}
		else
		{
			//此时找到我们想要的元素
			cout << "找到了,元素为" <<data[mid]<< endl;
			return;
		}
	}
	cout << "可惜没有找到" << endl;
}
int main()
{
	int arr[] = { 10,20,30,5,12 };
	bin_search(arr, 12, 5);
	return 0;
}