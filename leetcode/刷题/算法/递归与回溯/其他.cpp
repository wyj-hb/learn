//1.给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
//数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况
//class Solution {
//public:
//    vector<vector<int>> v1;
//    vector<int> v2;
//    bool panduan(vector<int> v1)//判断传入的序列是否是递增序列
//    {
//        for (int i = 0;i < v1.size() - 1;i++)
//        {
//            if (v1[i] > v1[i + 1])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//    void trace(vector<int>& nums, int startindedx, vector<bool>& b)
//    {
//        //查询每一个子序列，如果长度大于2并且是一个递增序列，那么便将其加入到序列中
//        if (v2.empty() || v2.size() == 1)
//        {
//
//        }
//        else
//        {
//            if (panduan(v2))
//            {
//                v1.push_back(v2);
//            }
//            if (!panduan(v2))
//            {
//                return;
//            }
//        }
//        for (int i = startindedx;i < nums.size();i++)
//        {
//            if (i > 0 && nums[i] == nums[i - 1] && b[i - 1] == false)
//            {
//                continue;
//            }
//            v2.push_back(nums[i]);
//            b[i] = true;
//            trace(nums, i + 1, b);
//            b[i] = false;
//            v2.pop_back();
//        }
//    }
//    vector<vector<int>> findSubsequences(vector<int>& nums)
//    {
//        int x = 0;
//        for (int i = 1;i < nums.size();i++)
//        {
//            if (nums[i] < nums[i - 1])
//            {
//                x = i;
//                break;
//            }
//        }
//        if (x == 0)
//        {
//            //说明按照递增顺序
//            vector<bool> b1(nums.size(), false);
//            trace(nums, 0, b1);
//            return v1;
//        }
//        vector<int> v2(nums.begin(), nums.begin() + x);
//        vector<bool> b1(v2.size(), false);
//        trace(v2, 0, b1);
//        return v1;
//    }
//};
//2.给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
//所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
//例如，行程["JFK", "LGA"] 与["JFK", "LGB"] 相比就更小，排序更靠前。
//假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。
// 自己写的，效率低,超时
//class Solution {
//public:
//    //分析:1.不能使用重复的，也就是说每次要在上一次坐标的下一个位置开始(startindex)
//    //因此无法保证第一个就是我们要取得首位置(jfk),因此我们不记录起始位置，每次递归从
//    //0开始，去重操作使用used数组实现
//    //2.每个机票都用一次，那么判断结束的条件就是v1.size()-1 == tickets.size()
//    vector<string> v1;
//    vector<vector<string>> v2;
//    void trace(vector<vector<string>>& tickets, vector<bool>& b1)
//    {
//        if (!v1.empty() && v1.size() == tickets.size() + 1)
//        {
//            v2.push_back(v1);
//        }
//        for (int i = 0;i < tickets.size();i++)
//        {
//            if (v1.empty())
//            {
//                //是空不必判断,此时没有要寻找的元素
//                if (tickets[i][0] == "JFK")
//                {
//                    //找到了
//                    b1[i] = true;//已经使用过
//                    v1.push_back(tickets[i][0]);
//                    v1.push_back(tickets[i][1]);
//                    trace(tickets, b1);
//                    b1[i] = false;
//                    v1.pop_back();
//                    v1.pop_back();
//                }
//                else
//                {
//                    //未找到
//                    continue;
//                }
//            }
//            else
//            {
//                //不为空，我们已经找到了
//                if (b1[i] == true)
//                {
//                    continue;//已经使用过，pass
//                }
//                //未曾使用过
//                if (tickets[i][0] == v1.back())
//                {
//                    v1.push_back(tickets[i][1]);
//                    b1[i] = true;
//                    trace(tickets, b1);
//                    b1[i] = false;
//                    v1.pop_back();
//                }
//                else
//                {
//                    continue;
//                }
//            }
//        }
//    }
//    //判断两个vector<string>
//    bool panduan(vector<string> v1, vector<string> v2)
//    {
//        for (int i = 0;i < v1.size();i++)
//        {
//            if (v1[i] == v2[i])
//            {
//                continue;
//            }
//            if (v1[i] > v2[i])
//            {
//                return false;
//            }
//            else
//            {
//                return true;
//            }
//        }
//        return true;
//    }
//    vector<string> findItinerary(vector<vector<string>>& tickets)
//    {
//        vector<bool> b1;
//        b1.resize(tickets.size(), false);
//        trace(tickets, b1);
//        if (v2.size() == 1)
//        {
//            return v2[0];
//        }
//        else if (v2.size() == 0)
//        {
//            vector<string> v3;
//            return v3;
//        }
//        else
//        {
//            vector<string> max = v2[0];
//            for (int i = 1;i < v2.size();i++)
//            {
//                if (panduan(max, v2[i]))
//                {
//                    max = max;
//                }
//                else
//                {
//                    max = v2[i];
//                }
//            }
//            return max;
//        }
//    }
//};
//class Solution {
//private:
//    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
//    unordered_map<string, map<string, int>> targets;
//    bool backtracking(int ticketNum, vector<string>& result) {
//        if (result.size() == ticketNum + 1) {
//            return true;
//        }
//        for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
//            if (target.second > 0) { // 记录到达机场是否飞过了
//                result.push_back(target.first);
//                target.second--;
//                if (backtracking(ticketNum, result)) return true;
//                result.pop_back();
//                target.second++;
//            }
//        }
//        return false;
//    }
//public:
//    vector<string> findItinerary(vector<vector<string>>& tickets) {
//        targets.clear();
//        vector<string> result;
//        for (const vector<string>& vec : tickets) {
//            targets[vec[0]][vec[1]]++; // 记录映射关系
//        }
//        result.push_back("JFK"); // 起始机场
//        backtracking(tickets.size(), result);
//        return result;
//    }
//};