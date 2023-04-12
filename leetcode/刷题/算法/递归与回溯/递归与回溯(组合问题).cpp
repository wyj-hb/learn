//1.给定两个整数 n 和 k，返回范围[1, n] 中所有可能的 k 个数的组合。
//你可以按 任何顺序 返回答案。
//class Solution {
//private:
//    vector<vector<int>> result; // 存放符合条件结果的集合
//    vector<int> path; // 用来存放符合条件结果
//    void backtracking(int n, int k, int startIndex) {
//        if (path.size() == k) {
//            result.push_back(path);
//            return;
//        }
//        for (int i = startIndex; i <= n; i++) {
//            path.push_back(i); // 处理节点 
//            backtracking(n, k, i + 1); // 递归
//            path.pop_back(); // 一层一层的回溯撤销
//        }
//    }
//public:
//    vector<vector<int>> combine(int n, int k) {
//        result.clear(); // 可以不写
//        path.clear();   // 可以不写
//        backtracking(n, k, 1);
//        return result;
//    }
//};
//2.给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
//candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
//对于给定的输入，保证和为 target 的不同组合数少于 150 个
//class Solution {
//public:
//    vector<int> path;
//    vector<vector<int>> result;
//    int sum = 0;
//    void trace(int target, vector<int>& candidates, int index)//index用于标注起始坐标
//    {
//        if (sum == target)
//        {
//            result.push_back(path);
//            return;
//        }
//        for (int i = index;i < candidates.size() && sum + candidates[i] <= target;i++)
//        {
//            sum += candidates[i];
//            path.push_back(candidates[i]);
//            trace(target, candidates, i);//i不需要加1，因为可以重复选择
//            sum -= candidates[i];
//            path.pop_back();
//        }
//    }
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
//    {
//        result.clear();
//        path.clear();
//        sort(candidates.begin(), candidates.end());
//        trace(target, candidates, 0);
//        return result;
//    }
//};
//3.给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//class Solution {
//public:
//    vector<string> v1;//返回结果
//    string s1;//暂时存放结果
//    //判断递归结束的条件是s1的大小等于digital.size()
//    void trace(string digits, map<int, string> m1, int index)
//    {
//        if (s1.size() == digits.size())
//        {
//            v1.push_back(s1);
//            return;
//        }
//        //从map中取出数字对应的字符串
//        string s = m1[digits[index] - '0'];
//        for (int i = 0;i < s.size();i++)//不需要传入下标因为操纵的是不同集合的元素
//        {
//            s1.push_back(s[i]);
//            index++;
//            trace(digits, m1, index);
//            index--;
//            s1.pop_back();
//        }
//    }
//    vector<string> letterCombinations(string digits)
//    {
//        //映射关系
//        map<int, string> m1{
//            {1,""},{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},
//            {9,"wxyz"}
//        };
//        if (digits.empty())
//        {
//            return v1;
//        }
//        trace(digits, m1, 0);
//        return v1;
//    }
//};
//4.给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//candidates 中的每个数字在每个组合中只能使用 一次 。
//注意：解集不能包含重复的组合。 
//class Solution {
//private:
//    vector<vector<int>> result;
//    vector<int> path;
//    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
//        if (sum == target) {
//            result.push_back(path);
//            return;
//        }
//        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
//            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
//                continue;
//            }
//            sum += candidates[i];
//            path.push_back(candidates[i]);
//            used[i] = true;
//            backtracking(candidates, target, sum, i + 1, used);
//            used[i] = false;
//            sum -= candidates[i];
//            path.pop_back();
//        }
//    }
//
//public:
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        vector<bool> used(candidates.size(), false);
//        path.clear();
//        result.clear();
//        // 首先把给candidates排序，让其相同的元素都挨在一起。
//        sort(candidates.begin(), candidates.end());
//        backtracking(candidates, target, 0, 0, used);
//        return result;
//    }
//};