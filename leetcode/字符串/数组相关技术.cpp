#include<iostream>
using namespace std;
//1.给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows)
//    {
//        vector<vector<int>> v1(numRows);
//        int rownum = 1;
//        for (int i = 0;i < numRows;i++)
//        {
//            //控制行打印
//            for (int j = 0;j < rownum;j++)
//            {
//                if (j == 0 || j == rownum - 1)
//                {
//                    v1[i].push_back(1);
//                }
//                else
//                {
//                    v1[i].push_back(v1[i - 1][j - 1] + v1[i - 1][j]);
//                }
//            }
//            rownum++;
//        }
//        return v1;
//    }
//}
//2.给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//class Solution {
//public:
//    vector<int> getRow(int rowIndex)
//    {
//        vector<vector<int>> v1(rowIndex + 1);
//        int rownum = 1;
//        for (int i = 0;i <= rowIndex;i++)
//        {
//            //控制行打印
//            for (int j = 0;j < rownum;j++)
//            {
//                if (j == 0 || j == rownum - 1)
//                {
//                    v1[i].push_back(1);
//                }
//                else
//                {
//                    v1[i].push_back(v1[i - 1][j - 1] + v1[i - 1][j]);
//                }
//            }
//            rownum++;
//        }
//        return v1[rowIndex];
//    }
////};
//3.给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//class Solution {
//public:
//    string reverseWords(string s) {
//        int x = 0;
//        for (int i = 0;i < s.size();i++)
//        {
//            if (s[i] == ' ')
//            {
//                int z = i - 1;
//                int y = i;
//                int len = x + (z - x) / 2;
//                while (z > len)
//                {
//                    int temp = s[z];
//                    s[z] = s[x];
//                    s[x] = temp;
//                    x++;
//                    z--;
//                }
//                x = y + 1;
//            }
//            if (i == s.size() - 1)
//            {
//                int z = i;
//                int len = x + (z - x) / 2;
//                while (z > len)
//                {
//                    int temp = s[z];
//                    s[z] = s[x];
//                    s[x] = temp;
//                    x++;
//                    z--;
//                }
//            }
//        }
//        return s;
//    }
//};
//4.已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0, 1, 2, 4, 5, 6, 7] 在变化后可能得到：
//若旋转 4 次，则可以得到[4, 5, 6, 7, 0, 1, 2]
//若旋转 7 次，则可以得到[0, 1, 2, 4, 5, 6, 7]
//注意，数组[a[0], a[1], a[2], ..., a[n - 1]] 旋转一次 的结果为数组[a[n - 1], a[0], a[1], a[2], ..., a[n - 2]] 。
//给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
//你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
//class Solution {
//public:
//    int findMin(vector<int>& nums)
//    {
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
//        return res[0];
//    }
//};