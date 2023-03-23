#include<iostream>
using namespace std;
//void merge(int arr[], int p, int q, int r)//p、q、r为位置
//{
//	int x1 = q - p + 1;//
//	int x2 = r - q;
//	int arr1[100];
//	int arr2[100];
//	int i = 0;
//	int j = 0;
//	for (;i < x1;i++)
//	{
//		arr1[i] = arr[p - 1 + i];
//	}
//	arr1[x1] = 1000;
//	for (;j < x2;j++)
//	{
//		arr2[j] = arr[q + j];
//	}
//	arr2[x2] = 1000;
//	int y1;
//	int y2 = 0;
//	int y3 = 0;
//	for (int y1 = p - 1;y1 < r;y1++)
//	{
//		if (arr1[y2] > arr2[y3])
//		{
//			arr[y1] = arr2[y3];
//			y3++;
//		}
//		else
//		{
//			arr[y1] = arr1[y2];
//			y2++;
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
//		merge(arr, p+1, q+1, r+1);
//	}
//}
//void quick(int arr[], int size, int lf, int rg)//rg
//{
//	int if_idx;
//	int rg_inx;
//	if(lf<rg)
//	{
//		if_idx = lf + 1;
//		rg_inx = rg;
//	step:
//		for (int i = if_idx;i < size;i++)
//		{
//			if (arr[i] >= arr[lf])
//			{
//				if_idx = i;//从左向右循环，找到第一个大于等于lf的值				break;
//				break;
//			}
//			if_idx++;//保持与i同步加加
//		}
//		for (int j = rg_inx;j >= lf + 1;j--)
//		{
//			if (arr[j] <= arr[lf])
//			{
//				rg_inx = j;
//				break;
//			}
//			rg_inx--;//保持同步减减
//		}
//		if (if_idx < rg_inx)
//		{
//			//交换
//			int tmp = arr[if_idx];
//			arr[if_idx] = arr[rg_inx];
//			arr[rg_inx] = tmp;
//			if_idx++;
//			rg_inx--;
//			goto step;
//		}
//		else
//		{
//			//此时i坐标后的都是大于lf的,j前的都是小于lf的
//			int tmp = arr[lf];
//			arr[lf] = arr[rg_inx];
//			arr[rg_inx] = tmp;
//			quick(arr, size, lf, rg_inx - 1);//lf右侧的数
//			quick(arr, size, rg_inx + 1, rg);//lf左侧
//		}
//	
//	}
//}
void jishu(int arr[], int size)
{
	for (int n = 1;n <= 100;n = n * 10)//n为基数，从n=1开始
	{
		int tmp[10][100] = { 0 };//10表示0-9,100表示存放的数据个数
		for (int i = 0;i < size;i++)
		{
			int m = (arr[i] / n) % 10;//n等于1表示求的是数字的个位，等于10时求的是十位
			tmp[m][i] = arr[i];//将数据放入到tmp中
		}//间接的将数据根据个位数字进行了排序
		int k = 0;
		int i = 0;
		for (int i = 0;i < 10;i++)
		{
			for (int j = 0;j < size;j++)
			{
				if (tmp[i][j] != 0)
				{
					//说明该位置有数据存在
					arr[k] = tmp[i][j];
					k++;
				}
			}
		}
	}
}
void shuchu(int arr[], int size)
{
	for (int i = 0;i < size;i++)
	{
		cout << arr[i] << " ";

	}
	cout << endl;
}
int main()
{
	int arr[] = { 16,25,39,27,12,8,45,63 };
	int size = sizeof(arr) / sizeof(arr[0]);
	/*maopao(arr,size);*/
	///*xuanze(arr, size);*/
	//charu(arr, size);
	/*xier(arr, size);*/
	/*merge_sort(arr, 0, 7);*/
	/*quick(arr, 8, 0, 7);*/
	jishu(arr, 8);
	shuchu(arr, size);
}
