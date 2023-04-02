#include<iostream>
using namespace std;
//1.编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
//class Solution {
//public:
//    void reverseString(vector<char>& s) {
//        int length = s.size();
//        for (int i = 0;i < length / 2;i++)
//        {
//            if (i != length - 1 - i)
//            {
//                char c = s[i];
//                s[i] = s[length - 1 - i];
//                s[length - 1 - i] = c;
//            }
//        }
//    }
//};
//2.给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 例如(a1, b1), (a2, b2), ..., (an, bn) ，使得从 1 到 n 的 min(ai, bi) 总和最大。
//返回该 最大总和 。
//class Solution {
//public:
//    int arrayPairSum(vector<int>& nums)
//    {
//        //先排序
//        int max = nums[0];
//        int min = nums[0];
//        for (int i = 1;i < nums.size();i++)
//        {
//            if (nums[i] > max)
//            {
//                max = nums[i];
//            }
//            if (nums[i] < min)
//            {
//                min = nums[i];
//            }
//        }
//        int length = max - min + 1;//要加的桶数
//        vector<int> num(length, 0);
//        for (int i = 0;i < nums.size();i++)
//        {
//            num[nums[i] - min]++;//计数
//        }
//        num[0]--;
//        for (int i = 1;i < length;i++)
//        {
//            num[i] += num[i - 1];
//        }
//        vector<int> res(nums.size(), 0);
//        for (int i = nums.size() - 1;i >= 0;i--)
//        {
//            res[num[nums[i] - min]] = nums[i];
//            num[nums[i] - min]--;
//        }
//        int sum = 0;
//        for (int i = 0;i < res.size();i += 2)
//        {
//            sum += res[i];
//        }
//        return sum;
//    }
//};
//3.给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
//class Solution {
//public:
//    int findMaxConsecutiveOnes(vector<int>& nums)
//    {
//        if (nums.size() == 1)
//        {
//            if (nums[0] == 1)
//            {
//                return 1;
//            }
//            else
//            {
//                return 0;
//            }
//        }
//        //定义快慢指针
//        int fast = 0;
//        int low = 0;
//        int len = 0;
//        while (fast < nums.size())
//        {
//            if (nums[low] != 1)
//            {
//                fast++;
//                low++;
//            }
//            else
//            {
//                while (fast < nums.size() && nums[fast] == 1)
//                {
//                    fast++;
//                }
//                len = len > (fast - low) ? len : (fast - low);
//                low = fast;
//                fast++;
//            }
//        }
//        return len;
//    }
//};
