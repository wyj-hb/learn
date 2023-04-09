#include<iostream>
#include<vector>
#include<string>
using namespace std;
//1.给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
//假设二叉树中至少有一个节点。
//class Solution {
//public:
//    int maxDepth = INT_MIN;
//    int result;
//    void traversal(TreeNode* root, int depth) {
//        if (root->left == NULL && root->right == NULL) {
//            if (depth > maxDepth) {
//                maxDepth = depth;
//                result = root->val;
//            }
//            return;
//        }
//        if (root->left) {
//            traversal(root->left, depth + 1); // 隐藏着回溯
//        }
//        if (root->right) {
//            traversal(root->right, depth + 1); // 隐藏着回溯
//        }
//        return;
//    }
//    int findBottomLeftValue(TreeNode* root) {
//        traversal(root, 0);
//        return result;
//    }
//};
//2.给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
//叶子节点 是指没有子节点的节点。
//class Solution {
//public:
//    void digui(TreeNode* root, vector<int>& v1, int sum)
//    {
//        if (!root->right && !root->left)
//        {
//            //叶子结点
//            sum += root->val;
//            v1.push_back(sum);
//        }
//        if (root->left)
//        {
//            sum += root->val;
//            digui(root->left, v1, sum);
//            sum -= root->val;
//        }
//        if (root->right)
//        {
//            sum += root->val;
//            digui(root->right, v1, sum);
//            sum -= root->val;
//        }
//    }
//    bool hasPathSum(TreeNode* root, int targetSum)
//    {
//        if (root == nullptr)
//        {
//            return false;
//        }
//        vector<int> v1;
//        digui(root, v1, 0);
//        if (count(v1.begin(), v1.end(), targetSum))
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//};