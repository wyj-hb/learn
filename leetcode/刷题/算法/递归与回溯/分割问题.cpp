//1.给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
//回文串 是正着读和反着读都一样的字符串。
//class Solution {
//public:
//    vector<vector<string>> v1;
//    vector<string> v2;
//    bool pandaun(string s, int start, int end)
//    {
//        int i = 0;
//        for (int i = start, j = end;i <= j;i++, j--)
//        {
//            if (s[i] != s[j])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//    void trace(int start, string s)
//    {
//        //判断结束条件
//        if (start >= s.size())
//        {
//            v1.push_back(v2);
//            return;
//        }
//        for (int i = start;i < s.size();i++)
//        {
//            if (pandaun(s, start, i))
//            {
//                //判断是否是回文串
//                v2.push_back(s.substr(start, i - start + 1));
//            }
//            else
//            {
//                continue;//继续循环直到找到回文子串为止
//            }
//            trace(i + 1, s);
//            v2.pop_back();
//        }
//    }
//    vector<vector<string>> partition(string s)
//    {
//        trace(0, s);
//        return v1;
//    }
//};
//2.有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
//例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
//给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
//class Solution {
//public:
//    vector<string> v;
//    bool panduan(string s, int start, int end)
//    {
//        if (start > end)
//        {
//            return false;
//        }
//        if (s[start] == '0' && start != end)
//        {
//            return false;
//        }
//        int num = 0;
//        for (int i = start;i <= end;i++)
//        {
//            if (s[i] > '9' || s[i] < '0')//排除点非字符
//            {
//                return false;
//            }
//            //判断是否越界
//            num = num * 10 + (s[i] - '0');
//            if (num > 255 || num < 0)
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//    void trace(string& s, int startindex, int pointnum)
//    {
//        if (pointnum == 3)
//        {
//            //分割完成，检查最后一个区间是否符合条件
//            if (panduan(s, startindex, s.size() - 1))
//            {
//                v.push_back(s);
//            }
//            return;
//        }
//        for (int i = startindex;i < s.size();i++)
//        {
//            if (panduan(s, startindex, i))
//            {
//                s.insert(s.begin() + i + 1, '.');
//                pointnum++;
//                trace(s, i + 2, pointnum);
//                pointnum--;
//                s.erase(s.begin() + i + 1);
//            }
//            else
//            {
//                //判断不成功只能break,说明本种方案不正确，排除
//                //原因:1.分配不正确2.出现错误字符
//                break;
//            }
//        }
//    }
//    vector<string> restoreIpAddresses(string s)
//    {
//        trace(s, 0, 0);
//        return v;
//    }
//};