//1.给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//class Solution {
//public:
//    vector<vector<int>> v1;
//    vector<int> v2;
//    int k = 0;
//    void trace(int k, int startindex, vector<int>& nums)
//    {
//        if (v2.size() == k && !v2.empty())
//        {
//            v1.push_back(v2);
//            return;
//        }
//        for (int i = startindex;i < nums.size();i++)
//        {
//            v2.push_back(nums[i]);
//            trace(k, i + 1, nums);
//            v2.pop_back();
//        }
//    }
//    vector<vector<int>> subsets(vector<int>& nums)
//    {
//        v1.push_back(v2);
//        for (int i = 1;i <= nums.size();i++)
//        {
//            trace(i, 0, nums);
//            v2.clear();
//        }
//
//        return v1;
//    }
//};
//2.给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
//解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
//class Solution {
//private:
//    vector<vector<int>> result;
//    vector<int> path;
//    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
//        result.push_back(path);
//        for (int i = startIndex; i < nums.size(); i++) {
//            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
//            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
//            // 而我们要对同一树层使用过的元素进行跳过
//            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
//                continue;
//            }
//            path.push_back(nums[i]);
//            used[i] = true;
//            backtracking(nums, i + 1, used);
//            used[i] = false;
//            path.pop_back();
//        }
//    }
//
//public:
//    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        result.clear();
//        path.clear();
//        vector<bool> used(nums.size(), false);
//        sort(nums.begin(), nums.end()); // 去重需要排序
//        backtracking(nums, 0, used);
//        return result;
//    }
//};