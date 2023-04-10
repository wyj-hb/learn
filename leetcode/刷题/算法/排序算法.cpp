//#include<iostream>
//1.给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案
//class Solution {
//public:
//    static bool cmp(pair<int, int> a, pair<int, int> b)
//    {
//        return a.second > b.second;
//    }
//    vector<int> topKFrequent(vector<int>& nums, int k)
//    {
//        //先对vector进行排序
//        sort(nums.begin(), nums.end());
//        vector<int> v1;
//        map<int, int> m1;//键是nums中值，value是值出现的频率
//        for (int i = 0;i < nums.size();i++)
//        {
//            m1[nums[i]]++;
//        }
//        vector< pair<int, int> > vec;
//        for (map<int, int>::iterator it = m1.begin(); it != m1.end(); it++)
//        {
//            vec.push_back(pair<int, int>(it->first, it->second));
//        }
//        sort(vec.begin(), vec.end(), cmp);
//        for (int i = 0;i < k;i++)
//        {
//            v1.push_back(vec[i].first);
//        }
//        return v1;
//    }
//};