//1.找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
//只使用数字1到9
//每个数字 最多使用一次 
//返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
//class Solution {
//public:
//    vector<int> v;
//    vector<vector<int>> v2;
//    int sum = 0;
//    void trace(int k, int n, vector<int> v1, int index)//k为数量限制，n为和
//    {
//        //返回条件
//        if (sum == n && v.size() == k)
//        {
//            v2.push_back(v);
//            return;
//        }
//        if (sum == n && v.size() != k)
//        {
//            return;
//        }
//        for (int i = index;i < v1.size() && sum + v1[i] <= n;i++)
//        {
//            v.push_back(v1[i]);
//            sum += v1[i];
//            trace(k, n, v1, i + 1);
//            v.pop_back();
//            sum -= v1[i];
//        }
//    }
//    vector<vector<int>> combinationSum3(int k, int n)
//    {
//        vector<int> v1{ 1,2,3,4,5,6,7,8,9 };
//        trace(k, n, v1, 0);
//        return v2;
//    }
//};
