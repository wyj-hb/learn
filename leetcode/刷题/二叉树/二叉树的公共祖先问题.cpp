//1.给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
//满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
//class Solution {
//public:
//    bool panduan(TreeNode* root1, TreeNode* root2)
//    {
//        if (!root1)
//        {
//            return false;
//        }
//        if (root1 == root2)
//        {
//            return true;
//        }
//        else if (!root1->left && !root1->right)//是叶子结点
//        {
//            return false;
//        }
//        else
//        {
//            auto a = panduan(root1->left, root2);
//            auto b = panduan(root1->right, root2);
//            return a || b;
//        }
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        if (panduan(root->left, p) && panduan(root->left, q))
//        {
//            //同时在左子树
//            return lowestCommonAncestor(root->left, p, q);
//        }
//        else if (panduan(root->right, p) && panduan(root->right, q))
//        {
//            return lowestCommonAncestor(root->right, p, q);
//        }
//        else
//        {
//            return root;
//        }
//    }
//};
//2.给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
//例如，给定如下二叉搜索树 : root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        if (!root || root == p || root == q)//因为root结点是绝对的p、q的祖先，若等于就返回
//        {
//            return root;
//        }
//        auto a = lowestCommonAncestor(root->left, p, q);
//        auto b = lowestCommonAncestor(root->right, p, q);
//        if (a && b)//在根节点的两侧
//        {
//            return root;
//        }
//        else
//        {
//            return a ? a : b;
//        }
//    }
//};