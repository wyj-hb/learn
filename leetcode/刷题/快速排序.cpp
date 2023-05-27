//#include<iostream>
//#include<vector>
//using namespace std;
//void printf(vector<int> v1)
//{
//	for (auto i : v1)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//}
////void swap(vector<int> &v1, int i, int j)
////{
////	//交换i、j位置的值
////	int temp = v1[i];
////	v1[i] = v1[j];
////	v1[j] = temp;
////}
////void quicksort(vector<int>& v, int left,int right)
////{
////	if (left >= right)
////	{
////		return;
////	}
////	int i = left;
////	int j = right;
////	while (left < right)
////	{
////		while (v[right] > v[left] && right > left)
////		{
////			right--;
////		}
////		if (left < right)
////		{
////			swap(v, left, right);
////			left++;
////		}
////		while (v[left] < v[right] && right > left)
////		{
////			left++;
////			//找到第一个v[left]大于等于v[right]的位置
////		}
////		if (left < right)
////		{
////			swap(v, left, right);
////			right--;
////		}
////	}  
////	quicksort(v, i,left-1);
////	quicksort(v, left + 1, j);
////}
//////void quick(vector<int> &v, int first, int end)
//////{
//////	if (first < end)
//////	{
//////		auto i = quicksort(v, first, end);
//////		quick(v, first,i-1);
//////		quick(v, i+1,end);
//////	}
//////}
////int main()
////{
////	srand((unsigned)time(NULL));
////	vector<int> v1;
////	for (int i = 0;i < 10;i++)
////	{
////		//随机生成5个数
////		v1.push_back(rand() % 10);
////	}
////	printf(v1);
////	quicksort(v1, 0, 9);
////	printf(v1);
////}
////归并排序
//void merge(vector<int> &v, vector<int> &v1,int left, int right, int mid)
//{
//	//范围:[left,mid] (mid,right];
//	//v为原容器,v1为排序后的容器
//	int i = left;
//	int j = mid + 1;
//	int k = left;
//	v1 = v;
//	while (i <= mid && j <= right)
//	{
//		if (v1[i] > v1[j])
//		{
//			v[k++] = v1[j++];
//		}
//		else
//		{
//			v[k++] = v1[i++];
//		}
//	}
//	if (i <= mid)
//	{
//		while (i <= mid)
//		{
//			v[k++] = v1[i++];
//		}
//	}
//	else
//	{
//		while (j <= right)
//		{
//			v[k++] = v1[j++];
//		}
//	}
//}
//void merge_sort(vector<int> &v,vector<int> &v1,int left,int right)
//{
//	if (left == right)//只有一个数
//	{
//		v1[left] = v[left];//放入对应的位置，逐渐可形成原容器
//	}
//	else
//	{
//		int mid = (right - left) / 2 + left;
//		merge_sort(v,v1,left, mid);
//		merge_sort(v,v1,mid + 1, right);
//		merge(v, v1, left, right, mid);
//	}
//}
//int main()
//{
//	srand((unsigned)time(NULL));
//	vector<int> v1;
//	for (int i = 0;i < 10;i++)
//	{
//		//随机生成5个数
//		v1.push_back(rand() % 10);
//	}
//	printf(v1);
//	vector<int> v(10, 0);
//	merge_sort(v1, v, 0, 9);
//	printf(v1);
//}