#include<iostream>
using namespace std;
//注意:这里的p、q均为第几个元素
void merge(int arr[], int p, int q, int r)//p、q分别为两个数组的开始
{
	int x1 = q - p + 1;//[p,q]
	int x2 = r - q;//[q+1,r]
	int arr1[100];//设置哨兵
	int arr2[100];
	int i = 0;
	for ( i = 0;i < x1;i++)
	{
		arr1[i] = arr[p + i - 1];
	}
	arr1[i] = 1000000;//哨兵
	int j = 0;
	for (j = 0;j < x2;j++)
	{
		arr2[j] = arr[q + j];
	}
	arr2[j] = 1000000;//哨兵
	int x = 0;int y = 0;
	for (int z = p - 1;z < r;z++)//进行两两比较，较小的放入到新数组中，由于设置了哨兵，因此不用判断是否出界
	{
		if (arr1[x] > arr2[y])
		{
			arr[z] = arr2[y];
			y++;
		}
		else
		{
			arr[z] = arr1[x];
			x++;
		}
	}
}
void merge_sort(int arr[], int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}
void shuchu(int arr[], int length)
{
	for (int i = 0;i < length;i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
	int arr[] = { 5,2,3,5,2,4,5,7,1,2,3,6,5,9,6 };
	merge_sort(arr, 0,15);
	shuchu(arr, 15);
}