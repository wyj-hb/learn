﻿#include<iostream>
//1.整数数组 nums 按升序排列，数组中的值 互不相同 。
//在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]（下标 从 0 开始 计数）。例如，[0, 1, 2, 4, 5, 6, 7] 
//在下标 3 处经旋转后可能变为 [4, 5, 6, 7, 0, 1, 2] 。
//给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回  - 1 。
//你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int l = 0, r = nums.size() - 1;
//        while (l <= r) {
//            int mid = l + ((r - l) >> 1);
//            if (nums[mid] >= nums[0]) {//左端有序
//                if (target >= nums[0] && nums[mid] >= target) r = mid - 1;
//                else l = mid + 1;
//            }
//            else {//右端有序
//                if (target < nums[0] && nums[mid] < target) l = mid + 1;
//                else r = mid - 1;
//            }
//        }
//        if (l >= nums.size() || nums[l] != target) return -1;
//        return l;
//    }
//};
//2.给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
//如果数组中不存在目标值 target，返回 [-1, -1]。
//你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
//vector<int> searchRange(vector<int>& nums, int target)
//{
//    //nums是递增的
//    //二分查找
//    int left = 0;
//    vector<int> v1{ -1,-1 };
//    int i = 0;//起始下标
//    int j = 0;//终止下标
//    int right = nums.size() - 1;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (nums[mid] == target)
//        {
//            while (mid - 1 >= 0 && nums[mid - 1] == nums[mid])
//            {
//                mid--;
//            }
//            v1[0] = mid;
//            while (mid + 1 < nums.size() && nums[mid + 1] == nums[mid])
//            {
//                mid++;
//            }
//            v1[1] = mid;
//            break;
//        }
//        else if (nums[mid] > target)
//        {
//            right = mid - 1;
//        }
//        else
//        {
//            left = mid + 1;
//        }
//    }
//    return v1;
//}
//};