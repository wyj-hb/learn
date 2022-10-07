#include <stdio.h>
//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//返回容器可以储存的最大水量。
//思路:两个指针碰撞，一个从开头出发，另一个从结尾出发，选择二者中小的为高度进行乘积，并对小的加加，再算出面积进行比较。
//int maxArea(int* height, int heightSize)
//{
//    int length = heightSize - 1;
//    int area = 0;
//    int i = 0;
//    int x = 0;
//    int y = heightSize - 1;
//    while (i < heightSize - 1 && length > i && y > 0)
//    {
//        if (height[i] > height[length])
//        {
//            x = height[length];
//            length--;
//            if (area < x * y)
//            {
//                area = x * y;
//            }
//        }
//        else
//        {
//            x = height[i];
//            i++;
//            if (area < x * y)
//            {
//                area = x * y;
//            }
//        }
//        y--;
//
//    }
//    return area;
//}
//int main()
//{
//    int arr[] = { 2,3,4,5,18,17,6 };
//    int a = maxArea(arr,7);
//    printf("%d", a);
//
//}
////给定一个含有 n 个正整数的数组和一个正整数 target 。
//找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl + 1, ..., numsr - 1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
//自己写的，无法记录最小长度
//int minSubArrayLen(int target, int* nums, int numsSize)
//{
//    int right = 0;
//    int left = 0;
//    int sum = 0;
//    while (left <= right && right < numsSize)
//    {
//        if (sum < target)
//        {
//            sum += nums[right];
//            right++;
//        }
//        else
//        {
//            if (sum -= nums[left] < target)
//            {
//                sum -= nums[left];
//                sum += nums[right];
//                right++;
//                left++;
//            }
//            else
//            {
//                sum -= nums[left];
//                left++;
//            }
//        }
//        
//    }
//    if(sum < )
//    return right - left;
//}
//int main()
//{
//    int target = 7;
//    int nums[] = { 2,3,1,2,4,3,7 };
//    int x = 7;
//    minSubArrayLen(target, nums, x);
//}
//思路：打开两个闭合窗口i,j,i先开始往右动，直到大于=目标值为止，若不大于，即一次循环未进，值不变，可据此判断是否为0.
//减去左值，判断是否仍大于等于，仍，左指针加加，继续减到小于，右指针加加到大于，每次的状态个数用count记录，每加加和减减都相应加减，进行多次比较，记录在变量min中
//int minSubArrayLen(int target, int* nums, int numsSize) {
//    int i, j, count = 0, sum = 0;
//    int min = numsSize + 1;
//    for (i = 0, j = 0; i < numsSize; i++) {
//        sum += nums[i];
//        count++;
//        while (sum - nums[j] >= target) {
//            sum = sum - nums[j++];
//            count--;
//        }
//        if (sum >= target) {
//            min = count < min ? count : min;
//        }
//    }
//    return min == numsSize + 1 ? 0 : min;
//}
//给你一个整数数组 nums ，请计算数组的 中心下标 。
//数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
//如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
//如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 - 1 。
//int pivotIndex(int* nums, int numsSize)
//{
//    int i = 0;
//    int sum1 = 0;
//    for (i = 0;i < numsSize;i++)
//    {
//        sum1 += nums[i];
//    }
//    int sum2 = 0;
//    int j = 0;
//    while (j < numsSize)
//    {
//        if (j > 0)
//        {
//            sum2 += nums[j - 1];
//        }
//        sum1 = sum1 - nums[j];
//        if (sum1 == sum2)
//        {
//            return j;
//            break;
//        }
//        j++;
//    }
//    return -1;
//}
int searchInsert(int* nums, int numsSize, int target)
{
    int low = 0;
    int mid = 0;
    int high = numsSize - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] > target)
        {
            high = mid - 1;
            return mid;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
            return mid;
        }
        else
        {
            return mid;
        }
    }
    return mid;
}
int main()
{
    int arr[] = { 1,3,5,6 };
    int numberSize = sizeof(arr)/4;
    int t = 2;
    int x = searchInsert(arr, numberSize, t);
    printf("%d", x);

}