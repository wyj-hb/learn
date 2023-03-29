//1.给定一个含有 n 个正整数的数组和一个正整数 target 。
//找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl + 1, ..., numsr - 1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums)
//    {
//        int left = 0;
//        int right = -1;
//        int sum = 0;
//        int minLen = nums.size() + 1;
//        while (left < nums.size())
//        {
//            if (sum < target && right + 1 < nums.size())
//            {
//                sum += nums[++right];
//            }
//            else
//            {
//                sum -= nums[left++];
//            }
//            if (sum >= target)
//            {
//                minLen = min(right - left + 1, minLen);
//            }
//        }
//        if (minLen == nums.size() + 1)
//        {
//            return 0;
//        }
//        return minLen;
//    }
//};