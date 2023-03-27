//#include<iostream>
//using namespace std;
//删除数组中的重复项，移动元素类型的题:
//1.给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
////请注意 ，必须在不复制数组的情况下原地对数组进行操作。
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        int length = 0;
//        for (int i = 0;i < nums.size();i++)
//        {
//            if (nums[i] != 0)
//            {
//                length++;
//            }
//        }
//        int j = 0;
//        for (int i = 0;i < nums.size();i++)
//        {
//            if (nums[i])
//            {
//                nums[j] = nums[i];
//                j++;
//            }
//        }
//        for (int i = length;i < nums.size();i++)
//        {
//            nums[i] = 0;
//        }
//    }
//};
//2.给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        int fast = 0;
//        int slow = 0;
//        while (fast < nums.size()) {
//            if (nums[fast] != val)
//            {
//                nums[slow] = nums[fast];
//                slow++;
//            }
//            fast++;
//        }
//        return slow;
//    }
//};
//3.给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
//由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。
//将最终结果插入 nums 的前 k 个位置后返回 k 。
//不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
//自己写:class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int length = nums.size();
//        int left = 0;
//        int right = 0;
//        int x = 0;
//        bool panduan = false;
//        while (right < length - 1)
//        {
//            while (nums[left] == nums[right] && right < length)
//            {
//                right++;
//                if (right == length)
//                {
//                    panduan = true;
//                    break;
//                }
//            }
//            if (panduan)
//            {
//                length = left + 1;
//                break;
//            }
//            int y = length - right;
//            int z = right;
//            for (int i = left;i < length && right < length;i++)
//            {
//                nums[i + 1] = nums[right];
//                right++;
//            }
//            x++;
//            length = length - z + left + 1;
//优解:class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//
//        if (nums.size() == 0)
//            return 0;
//        int k = 0;
//        for (int x : nums)
//            if (x > nums[k])
//                nums[++k] = x;
//        return k + 1;
//
//    }
//};
//4.给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (len < 2 || nums[i] != nums[len - 2])
                nums[len++] = nums[i];
        }
        return len;
    }
};*///解决n重复问题