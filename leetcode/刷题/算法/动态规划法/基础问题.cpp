//1.斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
//F(0) = 0，F(1) = 1
//F(n) = F(n - 1) + F(n - 2)，其中 n > 1
//给定 n ，请计算 F(n) 。
//class Solution {
//public:
//    int fib(int N) {
//        if (N <= 1) return N;
//        int dp[2];
//        dp[0] = 0;
//        dp[1] = 1;
//        for (int i = 2; i <= N; i++) {
//            int sum = dp[0] + dp[1];
//            dp[0] = dp[1];
//            dp[1] = sum;
//        }
//        return dp[1];
//    }
//};
//2.假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//class Solution {
//public:
//    int climbStairs(int n)
//    {
//        if (n <= 2)
//        {
//            return n;
//        }
//        //第一层一种，第二层两种，那么第三层就是第一层加2和第二层加一，也就是第一层加第二层
//        vector<int> dq(3);
//        dq[2] = 2;
//        dq[1] = 1;
//        int sum = 0;
//        for (int i = 3;i <= n;i++)
//        {
//            sum = dq[1] + dq[2];
//            dq[1] = dq[2];
//            dq[2] = sum;
//        }
//        return dq[2];
//    }
//};
//3.给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
//你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
//请你计算并返回达到楼梯顶部的最低花费。
//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost)
//    {
//        //选择i=0，从0开始爬
//        //i=1,从1开始爬
//        //最终距离等于length
//        int length = cost.size();
//        if (length == 2)
//        {
//            return min(cost[0], cost[1]);
//        }
//        vector<int> dp(length + 1);
//        dp[0] = 0;
//        dp[1] = 0;//可以选择下标，起初不花钱
//        int swap = 0;
//        for (int i = 2;i <= length;i++)
//        {
//            swap = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
//            dp[i] = swap;
//        }
//        return dp[length];
//        //1.dp[i]的含义:爬到第i层的最小花销
//        //2.递推公式:min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])
//        //3.初始化dp[0] = cost[0],dp[1] = cost[1]
//    }
//};
//4.一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
//问总共有多少条不同的路径？
//class Solution {
//public:
//    int uniquePaths(int m, int n)
//    {
        ////1.dp[i][j]的含义:表示到达该点时路径数
        ////2.递推公式 i==0 dp[i][j] = dp[i-1][j]+1;j == 0 dp[i][j-1]+1
        ////n!=0 dp[i][j] = dp[i-1][j]+dp[i][j-1]+1
        //vector<int> v1(n + 1);
        //vector<vector<int>> v2(m + 1, v1);
        //v2[1][1] = 0;
        //for (int i = 1;i <= m;i++)
        //{
        //    for (int j = 1;j <= n;j++)
        //    {
        //        if (i == 1 || j == 1)
        //        {
        //            v2[i][j] = 1;
        //        }
        //        else
        //        {
        //            v2[i][j] = v2[i][j - 1] + v2[i - 1][j];
        //        }
        //    }
        //}
        //return v2[m][n];
//    }
//};
//5.一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
//现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
//网格中的障碍物和空位置分别用 1 和 0 来表示。
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        if (obstacleGrid[0][0] == 1)
//            return 0;
//        vector<int> dp(obstacleGrid[0].size());
//        for (int j = 0; j < dp.size(); ++j)
//            if (obstacleGrid[0][j] == 1)
//                dp[j] = 0;
//            else if (j == 0)
//                dp[j] = 1;
//            else
//                dp[j] = dp[j - 1];
//
//        for (int i = 1; i < obstacleGrid.size(); ++i)
//            for (int j = 0; j < dp.size(); ++j) {
//                if (obstacleGrid[i][j] == 1)
//                    dp[j] = 0;
//                else if (j != 0)
//                    dp[j] = dp[j] + dp[j - 1];
//            }
//        return dp.back();
//    }
//};
//6.给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
//返回 你可以获得的最大乘积 。
//class Solution {
//public:
//    int integerBreak(int n) {
//        vector<int> dp(n + 1);
//        dp[2] = 1;
//        for (int i = 3; i <= n; i++) {
//            for (int j = 1; j <= i / 2; j++) {
//                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
//            }
//        }
//        return dp[n];
//    }
//};
//7.2给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
//class Solution {
//public:
//    int numTrees(int n)
//    {
//        if (n == 1)
//        {
//            return 1;
//        }
//        //1.确定dp[i]的含义:n为i时有dp[i]个二叉搜索树
//        //2.递推公式:dp[i] = 2*dp[i-1] + 2*dp[i-2] + 
//        vector<int> dp(n + 1, 0);
//        dp[2] = 2;
//        dp[1] = 1;
//        dp[0] = 1;
//        for (auto i = 3;i <= n;i++)
//        {
//            if (i % 2 != 0)
//            {
//                for (int j = 1;j <= i / 2;j++)
//                {
//                    dp[i] += 2 * (dp[i - j] * dp[j - 1]);
//                }
//                dp[i] += dp[i / 2] * dp[i / 2];
//            }
//            else
//            {
//                for (int j = 1;j <= i / 2;j++)
//                {
//                    dp[i] += 2 * (dp[i - j] * dp[j - 1]);
//                }
//            }
//        }
//        return dp[n];
//    }
//};
