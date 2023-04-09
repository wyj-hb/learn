#include<iostream>
using namespace std;
//1.给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
//你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null
//class Solution {
//public:
//    TreeNode* searchBST(TreeNode* root, int val)
//    {
//        if (root == nullptr)
//        {
//            return nullptr;
//        }
//        if (root->val == val)
//        {
//            return root;
//        }
//        else if (root->val > val)
//        {
//            return searchBST(root->left, val);
//        }
//        else
//        {
//            return searchBST(root->right, val);
//        }
//        return nullptr;
//    }
//};
//2.给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
//有效 二叉搜索树定义如下：
//节点的左子树只包含 小于 当前节点的数。
//节点的右子树只包含 大于 当前节点的数。
//所有左子树和右子树自身必须也是二叉搜索树
//class Solution {
//public:
//    void trace(vector<int>& v1, TreeNode* root)
//    {
//        if (root == nullptr) { return; }
//        trace(v1, root->left);
//        v1.push_back(root->val);
//        trace(v1, root->right);
//    }
//    bool isValidBST(TreeNode* root)
//    {
//        vector<int> result;
//        trace(result, root);
//        set<int> s1(result.begin(), result.end());
//        if (s1.size() != result.size())
//        {
//            return false;
//        }
//        auto v2 = result;
//        sort(v2.begin(), v2.end());
//        if (v2 == result)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//};
//3.给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
//差值是一个正数，其数值等于两值之差的绝对值。
//class Solution {
//public:
//    int min = INT_MAX;
//    void trace(TreeNode* root, vector<int>& v1)
//    {
//        if (!root) { return; }
//        trace(root->left, v1);
//        v1.push_back(root->val);
//        trace(root->right, v1);
//    }
//    int getMinimumDifference(TreeNode* root)
//    {
//        int min = INT_MAX;
//        vector<int> v1;
//        trace(root, v1);
//        for (int i = 1;i < v1.size();i++)
//        {
//            if (abs(v1[i] - v1[i - 1]) < min)
//            {
//                min = abs(v1[i] - v1[i - 1]);
//            }
//        }
//        return min;
//    }
//};
//4.给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
//如果树中有不止一个众数，可以按 任意顺序 返回。
//假定 BST 满足如下定义：
//结点左子树中所含节点的值 小于等于 当前节点的值
//结点右子树中所含节点的值 大于等于 当前节点的值
//左子树和右子树都是二叉搜索树
//class Solution {
//private:
//    int time;
//    int maxtime = 0;
//    vector <int> result;//用来储存所有的众数
//    TreeNode* pre;//用于中序遍历时存前结点
//    void getresult(TreeNode* root)
//    {
//        if (root == nullptr)
//            return;
//        getresult(root->left);//遍历左
//        if (pre == nullptr)//对前结点和当下结点进行数值比对
//            time = 1;
//        else if (pre->val == root->val)
//            time++;
//        else
//            time = 1;
//        pre = root;//更新pre;
//        if (time == maxtime)//如何出现的次数和最高次数一样，那需要将结果加进result中;
//            result.push_back(root->val);
//        if (time > maxtime)//当出现的次数超过最高次数时
//        {
//            result.clear();//需要将之前存的结果清除
//            maxtime = time;
//            result.push_back(root->val);//将最新的存入result中
//        }
//        getresult(root->right);//遍历右
//        return;
//    }
//public:
//    vector<int> findMode(TreeNode* root) {
//        time = 0;
//        maxtime = 0;
//        result.clear();
//        TreeNode* pre = nullptr;//记录前一个结点
//        getresult(root);
//        return result;
//
//    }
//};
//5.给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
//提醒一下，二叉搜索树满足下列约束条件：
//节点的左子树仅包含键 小于 节点键的节点。
//节点的右子树仅包含键 大于 节点键的节点。
//左右子树也必须是二叉搜索树。
//class Solution {
//public:
//    TreeNode* ptr = new TreeNode();
//    int sum = 0;
//    void trace(TreeNode*& root)
//    {
//        if (!root) { return; }
//        trace(root->right);
//        sum += root->val;
//        root->val = sum;
//        trace(root->left);
//    }
//    TreeNode* convertBST(TreeNode* root)
//    {
//        trace(root);
//        return root;
//    }
//};