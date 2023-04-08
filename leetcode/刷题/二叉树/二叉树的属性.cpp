#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
//1.给你一个二叉树的根节点 root ， 检查它是否轴对称。
//class Solution {
//public:
//    bool compare(TreeNode* left, TreeNode* right) {
//        // 首先排除空节点的情况
//        if (left == NULL && right != NULL) return false;
//        else if (left != NULL && right == NULL) return false;
//        else if (left == NULL && right == NULL) return true;
//        // 排除了空节点，再排除数值不相同的情况
//        else if (left->val != right->val) return false;
//
//        // 此时就是：左右节点都不为空，且数值相同的情况
//        // 此时才做递归，做下一层的判断
//        bool outside  = compare(left->left, right->right);   // 左子树：左、 右子树：右
//        bool inside  = compare(left->right, right->left);    // 左子树：右、 右子树：左
//        bool isSame = outside  && inside;                    // 左子树：中、 右子树：中 （逻辑处理）
//        return isSame;
//
//    }
//    bool isSymmetric(TreeNode* root) {
//        if (root == NULL) return true;
//        return compare(root->left, root->right);
//    }
//};
//2.给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//class Solution {
//public:
//    bool panduan(TreeNode* p, TreeNode* q)
//    {
//        if (p != NULL && q == NULL)
//        {
//            return false;
//        }
//        else if (p == NULL && q != NULL)
//        {
//            return false;
//        }
//        else if (p == NULL && q == NULL)
//        {
//            return true;
//        }
//        else if (p->val != q->val)
//        {
//            return false;
//        }
//        else
//        {
//            bool a = panduan(p->left, q->left);
//            bool b = panduan(p->right, q->right);
//            return a && b;
//        }
//    }
//    bool isSameTree(TreeNode* p, TreeNode* q)
//    {
//        return panduan(p, q);
//    }
//};
//3.给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。
//二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
//class Solution {
//public:
//    bool panduan(TreeNode* p, TreeNode* q)
//    {
//        if (p != NULL && q == NULL)
//        {
//            return false;
//        }
//        else if (p == NULL && q != NULL)
//        {
//            return false;
//        }
//        else if (p == NULL && q == NULL)
//        {
//            return true;
//        }
//        else if (p->val != q->val)
//        {
//            return false;
//        }
//        else
//        {
//            bool a = panduan(p->left, q->left);
//            bool b = panduan(p->right, q->right);
//            return a && b;
//        }
//    }
//    bool isSubtree(TreeNode* root, TreeNode* subRoot)
//    {
//        if (panduan(root, subRoot))
//        {
//            return true;
//        }
//        else if (root->left == NULL && root->right == NULL)
//        {
//            return false;
//        }
//        else if (root->left != NULL && root->right == NULL)
//        {
//            return isSubtree(root->left, subRoot);
//        }
//        else if (root->left == NULL && root->right != NULL)
//        {
//            return isSubtree(root->right, subRoot);
//        }
//        else
//        {
//            bool a = isSubtree(root->left, subRoot);
//            bool b = isSubtree(root->right, subRoot);
//            return a || b;
//        }
//    }
//};
//4.给定一个二叉树，找出其最大深度。
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//class Solution {
//public:
//    int maxDepth(TreeNode* root) {
//        if (root == NULL)
//        {
//            return 0;
//        }
//        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//    }
//};
//5.给定一个二叉树，找出其最小深度。
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//说明：叶子节点是指没有子节点的节点
//class Solution {
//public:
//    int minDepth(TreeNode* root)
//    {
//        if (root == NULL)
//        {
//            return 0;
//        }
//        else
//        {
//            int leftdepth = minDepth(root->left);
//            int rightdepth = minDepth(root->right);
//            if (root->left != NULL && root->right == NULL)
//            {
//                return leftdepth + 1;
//            }
//            else if (root->right != NULL && root->left == NULL)
//            {
//                return rightdepth + 1;
//            }
//            else
//            {
//                return min(leftdepth, rightdepth) + 1;
//            }
//        }
//    }
//};
//6.给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
//完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
//并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~2h 个节点
//class Solution {
//public:
//    int trace(TreeNode* root)
//    {
//        if (!root)return 0;
//        int left = trace(root->left);
//        int right = trace(root->right);
//        if (root->left != NULL && root->right == NULL)
//        {
//            return left + 1;
//        }
//        else if (root->right != NULL && root->left == NULL)
//        {
//            return right + 1;
//        }
//        else if (root->right == NULL && root->left == NULL)
//        {
//            return 0;
//        }
//        else
//        {
//            return left + right + 2;
//        }
//    }
//
//    int countNodes(TreeNode* root)
//    {
//        if (!root)
//        {
//            return 0;
//        }
//        return trace(root) + 1;
//    }
//};
//7.给定一个二叉树，判断它是否是高度平衡的二叉树。
//本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//class Solution {
//public:
//    //计算最大
    //int panduan1(TreeNode* root)
    //{
    //    if (root == NULL)
    //    {
    //        return 0;
    //    }
    //    else
    //    {
    //        return max(panduan1(root->left), panduan1(root->right)) + 1;
    //    }
    //}
//    bool isBalanced1(TreeNode* root)
//    {
//        return abs(panduan1(root->left) - panduan1(root->right)) > 1 ? false : true;
//    }
//    bool isBalanced(TreeNode* root)
//    {
//        if (root == NULL)
//        {
//            return true;
//        }
//        else if (isBalanced1(root) == false)
//        {
//            return false;
//        }
//        else
//        {
//            return isBalanced(root->right) && isBalanced(root->left);
//        }
//    }
//};
//8.给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
//叶子节点 是指没有子节点的节点。
//class Solution {
//public:
//    void conductpath(TreeNode* root, vector<string>& paths, string path)
//    {
//        if (root != NULL)
//        {
//            path += to_string(root->val);
//            if (root->left == NULL && root->right == NULL)
//            {
//                //说明该节点是叶子结点
//                paths.push_back(path);
//            }
//            else
//            {
//                path += "->";
//                conductpath(root->left, paths, path);
//                conductpath(root->right, paths, path);
//            }
//        }
//
//    }
//    vector<string> binaryTreePaths(TreeNode* root)
//    {
//        vector<string> v1;
//        conductpath(root, v1, "");
//        return v1;
//    }
//};
//9.给定二叉树的根节点 root ，返回所有左叶子之和。
//class Solution {
//public:
//    int sumOfLeftLeaves(TreeNode* root) {
//        if (root == NULL) return 0;
//        int leftValue = 0;
//        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
//            leftValue = root->left->val;
//        }
//        return leftValue + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
//    }
//};

