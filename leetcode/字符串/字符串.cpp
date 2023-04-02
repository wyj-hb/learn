#include<iostream>
#include<string>
using namespace std;
//1.编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""
//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        string s1 = "";
//        int len1 = strs.size();
//        if (len1 == 0)
//        {
//            return s1;
//        }
//        int min = 1000;
//        for (int i = 0;i < len1;i++)
//        {
//            if (min < strs[i].size())
//            {
//                min = strs[i].size();
//            }
//        }
//        bool panduan = true;
//        int y = 0;
//        for (int i = 0;i < min && y < len1;i++)
//        {
//
//            for (int j = 0;j < len1 - 1;j++)
//            {
//                if (strs[j][i] == strs[j + 1][i])
//                {
//                    continue;
//                }
//                return s1;
//            }
//            s1 += strs[y][i];
//            y++;
//            continue;
//
//        }
//        return s1;
//    }
//};
//2.给你一个字符串 s，找到 s 中最长的回文子串。
//如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
//class Solution
//{
//public:
//    string longestPalindrome(string s)
//    {
//        int i0 = 0;
//        int j0 = 0;
//        int len = s.size();
//        for (int i = 1;i < len;i++)
//        {
//            //奇数
//            int x = i;
//            int y = i;
//            while (x < len - 1 && y>0)
//            {
//                if (s[x + 1] == s[y - 1])
//                {
//                    x++;
//                    y--;
//                    continue;
//                }
//                else
//                {
//                    break;
//                }
//            }
//            if (x - y > j0 - i0)
//            {
//                j0 = x;
//                i0 = y;
//            }
//            //偶数
//            x = i;
//            y = i - 1;
//            while (x > 0 && y < len - 1)
//            {
//                if (s[x - 1] == s[y + 1])
//                {
//                    x--;
//                    y++;
//                }
//                else
//                {
//                    break;
//                }
//            }
//            if (y - x > j0 - i0)
//            {
//                i0 = x;
//                j0 = y;
//            }
//        }
//        return s.substr(i0, j0 - i0 + 1);
//    }
//};
//3.给你一个字符串 s ，请你反转字符串中 单词 的顺序。
//单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
//返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
//注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
//class Solution {
//public:
//    string reverseWords(string s)
//    {
//        //去除首尾及多余空格
//        auto a = s.begin();
//        while (a != s.end())
//        {
//            if (*a == ' ' && *(a + 1) == ' ')
//            {
//                a = s.erase(a);
//            }
//            else
//            {
//                a++;
//            }
//        }
//        auto b = s.begin();
//        if (s[0] == ' ')
//        {
//            s.erase(b);
//        }
//        auto c = s.end();
//        if (s[s.size() - 1] == ' ')
//        {
//            s.erase(c - 1);
//        }
//        int j = s.size() - 1;
//        reverse(s.begin(), s.end());
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
//            if (i  == s.size() - 1)
//            {
//                int z  = i;
//                int len  = x + (z - x) / 2;
//                while (z > len)
//                {
//                    int temp  = s[z];
//                    s[z] = s[x];
//                    s[x] = temp;
//                    x++;
//                    z--;
//                }
//            }
//
//        }
//        return s;
//    }
////};
//4.给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  - 1 。
//int strStr(string haystack, string needle)
//{
//    //创建next数组
//    int next[100];
//    next[0] = -1;
//    int i = 0;
//    int j = -1;
//    while (i < needle.size())
//    {
//        if (j == -1 || needle[j] == needle[i])
//        {
//            j++;
//            i++;
//            if (i < needle.size())
//            {
//                next[i] = j;
//            }
//        }
//        else
//        {
//            j = next[j];
//        }
//    }
//    i = 0;
//    j = 0;
//    while ((i < haystack.size() && j < needle.size()) || j == -1)
//    {
//        if (j == -1 || haystack[i] == needle[j])
//        {
//            i++;
//            j++;
//        }
//        else
//        {
//            j = next[j];
//        }
//    }
//    if (j == needle.size())
//    {
//        return i - needle.size();
//    }
//    else
//    {
//        return -1;
//    }
//}
//int main()
//{
//    int a = strStr("hello", "ll");
//    cout << a << endl;
//}