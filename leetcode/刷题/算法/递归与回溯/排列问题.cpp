//1.给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
//class Solution {
//public:
//    vector<int> v1;
//    vector<vector<int>> v2;
//    void trace(vector<bool>& b1, vector<bool>& b2, vector<int>& nums)
//    {
//        if (v1.size() == nums.size())
//        {
//            v2.push_back(v1);
//            return;
//        }
//        for (int i = 0;i < nums.size();i++)
//        {
//            //判断是否在同一树枝上使用过，因为我们并未设计startindex变量
//            if (b2[i] == true)//true代表使用过
//            {
//                continue;
//            }
//            //首先判断是否在同一树层上使用过
//            if (i > 0 && nums[i - 1] == nums[i] && b1[i - 1] == false)
//            {
//                continue;
//            }
//            v1.push_back(nums[i]);
//            b1[i] = true;
//            b2[i] = true;
//            trace(b1, b2, nums);
//            v1.pop_back();
//            b1[i] = false;
//            b2[i] = false;
//        }
//    }
//    vector<vector<int>> permuteUnique(vector<int>& nums)
//    {
//        vector<bool> b1(nums.size(), false);
//        vector<bool> b2(nums.size(), false);
//        sort(nums.begin(), nums.end());
//        trace(b1, b2, nums);
//        return v2;
//    }
//};
//2.给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
//class Solution {
//public:
//    //容器打乱顺序的任何一种组合方式
//    vector<vector<int>> v1;
//    vector<int> v2;
//    void trace(vector<bool>& b1, vector<int>& nums)
//    {
//        if (nums.size() == v2.size())
//        {
//            v1.push_back(v2);
//            return;
//        }
//        for (int i = 0;i < nums.size();i++)
//        {
//            if (b1[i] == true) { continue; }//说明使用过
//            b1[i] = true;
//            v2.push_back(nums[i]);
//            trace(b1, nums);
//            v2.pop_back();
//            b1[i] = false;
//        }
//    }
//    vector<vector<int>> permute(vector<int>& nums)
//    {
//        vector<bool> b1(nums.size(), false);
//        trace(b1, nums);
//        return v1;
//    }
//};