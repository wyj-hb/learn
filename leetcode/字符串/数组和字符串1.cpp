#include<iostream>
using namespace std;
//1.给你一个整数数组 nums ，请计算数组的 中心下标 。
//数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
//如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
//如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 - 1 。
//class Solution {
//public:
//    int pivotIndex(vector<int>& nums)
//    {
//        if (nums.size() == 1)
//        {
//            return 0;
//        }
//        int sum1 = 0;
//        int x = 0;
//        int sum2 = 0;
//        for (int i = 1;i < nums.size();i++)
//        {
//            sum2 += nums[i];
//        }
//        int z = sum2;
//        while (x + 1 < nums.size())
//        {
//            if (sum2 == sum1)
//            {
//                return x;
//            }
//            sum2 -= nums[x + 1];
//            sum1 += nums[x++];
//        }
//        if (z + nums[0] - nums[nums.size() - 1] == 0)
//        {
//            return nums.size() - 1;
//        }
//        return -1;
//    }
//};
//2.给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//请必须使用时间复杂度为 O(log n) 的算法。
//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        while (left <= right)
//        {
//            int mid = (left + right) / 2;
//            if (nums[mid] == target)
//                return mid;
//            else if (nums[mid] < target)
//                left = mid + 1;
//            else
//                right = mid - 1;
//        }
//        return left;
//    }
//};
//int sort_t(int arr[], int first,int end)
//{
//	int i = first;
//	int j = end;
//	while (i < j)
//	{
//		while( arr[i] <= 0 && i < j)//由于0是实数，但是既不属于正实数也不属于正实数，所以遇到元素0跳过
//		{
//			i = i + 1;
//		}
//		while (arr[j]>=0 && j > i)
//		{
//			j = j - 1;
//		}
//		if (i < j)//找到符合条件的i,j值就进行交换
//		{
//			int temp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = temp;
//		}
//	}
//	return i;
//}
//void quicksort(int arr[], int first, int end)
//{
//	if (first < end)
//	{
//		int p = sort_t(arr, first, end);
//		quicksort(arr, first, p - 1);
//		quicksort(arr, p + 1, end);
//	}
//}
//int main()
//{
//	int arr[] = { -1,2,-5,0,1,2,-6 };
//	int length = sizeof(arr) / sizeof(int);
//	sort_t(arr, 0,length-1);
//	for (int i = 0;i < length;i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//4.以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
//class Solution {
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        int n = intervals.size();
//        if (n == 1)
//            return intervals;
//        sort(intervals.begin(), intervals.end());
//        vector<vector<int>> vec;
//        vec.push_back(intervals[0]);
//        int j = 0;
//        for (int i = j + 1;i < n;i++) {
//            if (intervals[i][0] <= vec[j][1])
//                vec[j][1] = max(vec[j][1], intervals[i][1]);
//            else {
//                vec.push_back(intervals[i]);
//                j++;
//            }
//        }
//        return vec;
//    }
//};