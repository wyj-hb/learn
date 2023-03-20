#include<iostream>
using namespace std;
//2.3 - 2重写过程 MERGE，使之不使用哨兵，而是一旦数组L或R的所有元素均被复制回A就立即停止，将另一数组的剩余部分复制回A月2的
//注意:这里的p、q均为第几个元素
//void merge(int arr[], int p, int q, int r)//p、q分别为两个数组的开始
//{
//	int x1 = q - p + 1;//[p,q]
//	int x2 = r - q;//[q+1,r]
//	int arr1[100];//设置哨兵
//	int arr2[100];
//	int i = 0;
//	for (i = 0;i < x1;i++)
//	{
//		arr1[i] = arr[p + i - 1];
//	}
//	//arr1[i] = 1000000;//哨兵
//	int j = 0;
//	for (j = 0;j < x2;j++)
//	{
//		arr2[j] = arr[q + j];
//	}
//	//arr2[j] = 1000000;//哨兵
//	int x = 0;int y = 0;
//	int z = 0;
//	for (z = p - 1;z < r && x<x1 && y < x2;z++)//进行两两比较，较小的放入到新数组中，由于设置了哨兵，因此不用判断是否出界
//	{
//		if (arr1[x] > arr2[y])
//		{
//			arr[z] = arr2[y];
//			y++;
//		}
//		else
//		{
//			arr[z] = arr1[x];
//			x++;
//		}
//	}
//	if (x == x1)
//	{
//		//此时arr1数组已经全部复制过去
//		for (int i = y;i < x2;i++)
//		{
//			arr[z] = arr2[i];
//			z++;
//		}
//	}
//	else
//	{
//		for (int i = x;i < x1;i++)
//		{
//			arr[z] = arr1[i];
//			z++;
//		}
//	}
//}
//void merge_sort(int arr[], int p, int r)
//{
//	if (p < r)
//	{
//		int q = (p + r) / 2;
//		merge_sort(arr, p, q);
//		merge_sort(arr, q + 1, r);
//		merge(arr, p, q, r);
//	}
//}
//void shuchu(int arr[], int length)
//{
//	for (int i = 0;i < length;i++)
//	{
//		cout << arr[i] << " ";
//	}
//}
//int main()
//{
//	int arr[] = { 5,2,3,5,2,4,5,7,1,2,3,6,5,9,6 };
//	merge_sort(arr, 0, 15);
//	shuchu(arr, 15);
//}
//插入排序
//升序版本
//void charu(int arr[], int length)
//{
//	for (int i = 1;i < length;i++)
//	{
//		int key = arr[i];
//		int j = i - 1;
//		while(key < arr[j] && i>=0)
//		{
//			arr[j+1] = arr[j];
//			j--;
//		}
//		arr[j + 1] = key;
//	}
//}
////二分查找
//起始和终止指的都是下标
//int search(int nums[], int size, int left,int target) //nums是数组，size是数组的大小，target是需要查找的值
//{
//	int right = size - 1;	// 定义了target在左闭右闭的区间内，[left, right]
//	while (left <= right) {	//当left == right时，区间[left, right]仍然有效
//		int middle = left + ((right - left) / 2);//等同于 (left + right) / 2，防止溢出
//		if (nums[middle] > target) {
//			right = middle - 1;	//target在左区间，所以[left, middle - 1]
//		}
//		else if (nums[middle] < target) {
//			left = middle + 1;	//target在右区间，所以[middle + 1, right]
//		}
//		else {	//既不在左边，也不在右边，那就是找到答案了
//			return middle;
//		}
//	}
//	//没有找到目标值
//	return -1;
//}
//int binarySearch(int a[], int x, int left, int right)
//{
//	int mid = (left + right) / 2;
//	if (a[mid] < x)
//	binarySearch(a, x, mid + 1, right);
//	else if (a[mid] == x)
//		return mid;
//	else if (a[mid] > x)
//		binarySearch(a, x, left, mid - 1);
//	else if (left > right)
//		return -1;//表示没有找到
//	
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6};
//	charu(arr, 6);
//	/*int x = search(arr, 6, 6);*/
//	int x = binarySearch(arr,6,0,5);
//	cout << x << endl;
//}
//2.3 - 7 描述一个运行时间为(nlgn)的算法，给定n个整数的集合S和另一个整数x, 该算法能确定S中是否存在两个其和刚好为x的元素。
//先使用merge-sort，在使用二分查找
//二分查找是lgn,for循环是n，相乘的话是n*lgn,而merge_sort也是n*lgn,因此线性相加，级数不变
//int main()
//{
//	int arr[] = { 15,20,12,3,5,6,2,15,18 };
//	merge_sort(arr,0,9);
//	for (int i = 0;i < 9;i++)
//	{
//		if (arr[i] < 18)
//		{
//			int z = search(arr, 9, i + 1, 18 - arr[i]);
//			if (z!=-1)
//			{
//				cout << arr[z] << endl;
//				cout << arr[i] << endl;
//				break;
//			}
//		}
//	}
//}
//朴素的多项式求值法
//int power(int x,int i)//求x的i次方
//{
//	int s = x;
//	if (i == 0)
//	{
//		return 1;
//	}
//	for (int z = 1;z < i;z++)
//	{
//		x *= s;
//	}
//	return x;
//}
//int qiuhe(int arr[], int x)//数组arr中存放的是常数ax
//{
//	int sum = 0;
//	int size = sizeof(arr) / sizeof(int);
//	for (int i = 0;i < size;i++)
//	{
//		sum += arr[i] * power(x, i);
//	}
//}
//2 - 4 （逆序对） 假设A[1...n] 是一个由n个不同数得到数组。若i<j且A[i]>A[j], 则对偶(i, j) 称为A的一个逆序对(inversion)
//a.列出数组的5个逆序对
//b.由集合中的元素构成的什么数组具有最多的逆序对？它有多少逆序对？
//c.插入排序的运行时间与输入数组中逆序对的数量之间是什么关系？证明你的回答。
//d.给出一个确定在n个元素的任何排列中逆序对数量的算法，最坏情况需要nlgn 时间。（提示：修改归并排序）
//使用归并排序法
int merge(int arr[], int p, int q, int r)
{
	int sum = 0;
	int x1 = q - p + 1;
	int x2 = r - q;
	int arr1[100];
	int arr2[100];
	int i = 0;
		int j = 0;
	for (int i = 0;i < x1;i++)
	{
		arr1[i] = arr[p - 1 + i];
	}
	for (int j = 0;j < x2;j++)
	{
		arr2[j] = arr[q+i];
	}
	int y1 = 0;
	int y2 = 0;
	int y3 = 0;
	bool x = false;
	for (y1 = p - 1;y1 <= r-1 && y2<x1 && y3<x2 ;)
	{
		/*int z = y3;*/
		while(arr1[y2] > arr2[y3] && y2 < x1 && y3 < x2)
		{
			arr[y1] = arr2[y3];
			/*if (!x)
			{
				arr[y1] = arr2[y3];
			}*/
			x = true;
			y1++;
			y3++;
		}
		if (x)
		{
			sum += y3;
			x = false;
			//y3 = z;
			//y3++;
		}
		if(arr1[y2] <= arr2[y3] && y2 < x1 && y3 < x2)
		{
			arr[y1] = arr1[y2];
			y2++;
			y1++;
		}
	}
	if (x1 == y2)
	{
		for (int i = y3;i < x2;i++)
		{
			arr[y1] = arr2[i];
		}
	}
	else
	{
		for (int i = y2;i < x1;i++)
		{
			arr[y1] = arr1[i];
		}
	}
	return sum;
}
int merge_sort(int arr[], int p, int r)
{
	int sum= 0;
	if (p < r)
	{
		int q = (p + r) / 2;
		sum += merge_sort(arr, p, q);
		sum += merge_sort(arr, q + 1, r);
		sum += merge(arr, p+1, q+1, r+1);
	}
	return sum;
}
int main()
{
	int arr[] = {10,2,5,4,5,6};
	int sum = merge_sort(arr, 0, 5);
	cout << sum << endl;
}

