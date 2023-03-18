#include<iostream>
using namespace std;
//插入算法
//按照升序排列
//void shengxu(int* arr,int length)
//{
//	for (int i = 1;i < length;i++)
//	{
//		int key = arr[i];//用以保存arr[i]的值
//		int	j = i - 1;
//		while(j >= 0 && key < arr[j])//把key的值拿出来i后面数组中的每一个值进行比较，直到找到一个比他小的或者到头为止，此时还原其为key的值
//		{
//			arr[j + 1] = arr[j];
//			j--;
//		}
//		arr[j+1] = key;//令该位置的值为key值，使得key的值可以放置到正确的位置
//	}
//}
////按照降序排列
//void jiangxu(int arr[], int length)
//{
//	for (int i = 1;i < length;i++)
//	{
//		int key = arr[i];//用以保存arr[i]的值
//		int	j = i - 1;
//		while (j >= 0 && key >= arr[j])//把key的值拿出来i后面数组中的每一个值进行比较，直到找到一个比他小的或者到头为止，此时还原其为key的值
//		{
//			arr[j + 1] = arr[j];
//			j--;
//		}
//		arr[j + 1] = key;//令该位置的值为key值，使得key的值可以放置到正确的位置
//	}
//}
//void print(int arr[], int length)
//{
//	for (int i = 0;i < length;i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	int arr[10] = { 10,16,2,18,12,12,132,5,6,8 };
//	shengxu(arr, 10);
//	print(arr, 10);
//	jiangxu(arr, 10);
//	print(arr, 10);
//}
//2.1 - 4 考虑把两个n位二进制整数加起来的问题，这两个整数分别存储在两个n元数组A和B
//中。这两个整数的和应按二进制形式存储在一个(n + 1)元数组C中。请给出该问题的形式化描述，并写出伪代码。
//double power(int x,int n)//设计一个求x的n次方的函数
//{
//	if (n == 0)
//	{
//		return 1;
//	}
//	while (n>1)
//	{
//		x *= 2;
//		n--;
//	}
//	return x;
//}
////void jiashang(int arr3[], int arr[],int n)
////{
////	int x = sizeof(arr) / 4;
////	for (int i = x;i < n;i++)
////	{
////		arr3[i] = arr[i];
////	}
////}
//void xiangjia(int arr1[], int arr2[], int arr3[], int n)
//{
//	int i = 0;
//	for (;i < n - 1/*(sizeof(arr1) < sizeof(arr2)) ? sizeof(arr1) / 4 : sizeof(arr2) / 4*/;i++)
//	{
//		arr3[i] += (arr1[i] + arr2[i]);
//		if (arr3[i] > 1)//进位
//		{
//			arr3[i + 1] += 1;
//			arr3[i] = 0;
//		}
//	}
//	/*if (sizeof(arr1) < sizeof(arr2))
//	{
//		jiashang(arr3, arr2,n);
//	}
//	else
//	{
//		jiashang(arr3, arr1, n);
//	}*/
//}
//int shuchu(int arr[],int n)//将二进制的数十进制输出
//{
//	int sum = 0;
//	for (int x = 0;x < n;x++)
//	{
//		sum += arr[x] * power(2, x);
//	}
//	return sum;
//}
//int main()
//{
//	int arr1[5] = { 1,0,1,0,1 };
//	int arr2[5] = { 1,0,1,0,0 };
//	int arr3[6] = { 0,0,0,0,0,0 };
//	xiangjia(arr1, arr2, arr3, 6);
//	double x = shuchu(arr3, 6);
//	cout << x << endl;
//}
//2.2-3考虑排序存储在数组A中的n个数:首先找出A中的最小元素并将其与A[1]中的元素进牌行交换。接着，找出A中的次最小元素
//并将其与 A[2]中的元素进行交换。对A中前n - 1
//个元素按该方式继续。该算法称为选择算法，写出其伪代码。该算法维持的循环不变式是什么 ?
//  为什么它只需要对前n - 1个元元素，而不是对所有n个元素运行 ? 用日记号给出选择排序的最好情况与最坏情况运行时
//void swap(int &x1, int &x2)
//{
//	int temp = x1;
//	x1 = x2;
//	x2 = temp;
//}
//void paixu(int arr[],int n)
//{
//	for (int i = 0;i < n-1;i++)
//	{
//		int minx = arr[i];
//		int xiabiao = i;
//		for (int j = i + 1;j < n - 1;j++)
//		{
//			if (arr[j] < minx)
//			{
//				minx = arr[j];
//				xiabiao = j;
//			}
//		}
//		swap(arr[i], arr[xiabiao]);
//	}
//}
//2. 2 - 3 再次考虑线性查找问题(参见练习 2.1 - 3)。假定要查找的元素等可能地为数组中的任意元
//间。
//素，平均需要检查输人序列的多少元素 ? 平均情况和最坏情况运行时间。证明你的