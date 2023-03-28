using namespace std;
#include<iostream>
#include<string>
//1.给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。
//如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。以长度为 2 的整数数组
//[index1, index2] 的形式返回这两个整数的下标 index1 和 index2。你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用
//相同的元素。你所设计的解决方案必须只使用常量级的额外空间。
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& numbers, int target) {
//        vector v1(2, 0);
//        int left = 0;
//        int right = numbers.size() - 1;
//        while (left < right)
//        {
//            if (numbers[left] + numbers[right] > target)
//            {
//                right--;
//            }
//            else if (numbers[left] + numbers[right] < target)
//            {
//                left++;
//            }
//            else
//            {
//                v1[0] = left + 1;
//                v1[1] = right + 1;
//                return v1;
//            }
//        }
//        return v1;
//    }
//};
//2.如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
//字母和数字都属于字母数字字符。
//给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
//class Solution {
//public:
//    bool isPalindrome(string s) {
//        string s2(s.size(), 0);
//        int length = 0;
//        for (int i = 0;i < s.size();i++)
//        {
//            if (s[i] >= 65 && s[i] <= 90)
//            {
//                s2[length] = tolower(s[i]);
//                length++;
//            }
//            else if (s[i] >= 97 && s[i] <= 122)
//            {
//                s2[length] = s[i];
//                length++;
//            }
//            else if (s[i] >= '0' && s[i] <= '9')
//            {
//                s2[length] = s[i];
//                length++;
//            }
//            else
//            {
//                continue;
//            }
//        }
//        int left = 0;
//        int right = length - 1;
//        while (left <= right)
//        {
//            if (s2[left] != s2[right])
//            {
//                return false;
//            }
//            else
//            {
//                left++;
//                right--;
//            }
//        }
//        return true;
//    }
//};
//3.给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
//元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。
//class Solution {
//public:
//    string reverseVowels(string s) {
//        int left = 0;
//        int right = s.size() - 1;
//        string s1 = "aeiouAEIOU";
//        while (left < right)
//        {
//            auto x1 = s1.find(s[left]);
//            if (x1 != string::npos)
//            {
//                while (left < right)
//                {
//                    auto y1 = s1.find(s[right]);
//                    if (y1 == string::npos)
//                    {
//                        right--;
//                    }
//                    else
//                    {
//                        int temp = s[left];
//                        s[left] = s[right];
//                        s[right] = temp;
//                        left++;
//                        right--;
//                        break;
//                    }
//                }
//
//            }
//            else
//            {
//                left++;
//            }
//        }
//        return s;
//    }
//};
//4.给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//返回容器可以储存的最大水量。
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int left = 0;
//        int right = height.size() - 1;
//        int max1 = 0;
//        while (left < right)
//        {
//            max1 = (right - left) * min(height[right], height[left]) > max1 ? (right - left) * min(height[right], height[left]) : max1;
//            if (height[left] > height[right])
//            {
//                right--;
//            }
//            else
//            {
//                left++;
//            }
//        }
//        return max1;
//    }
//};
