#include<iostream>
#include<vector>
#include<string>
using namespace std;
//1.给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
//class Solution {
//public:
//    void trace(TreeNode* root, vector<int>& v1)
//    {
//        if (root == NULL)
//        {
//            return;
//        }
//        else
//        {
//            v1.push_back(root->val);
//            trace(root->left, v1);
//            trace(root->right, v1);
//        }
//    }
//    vector<int> preorderTraversal(TreeNode* root)
//    {
//        vector<int> result;
//        trace(root, result);
//        return result;
//    }
//};
//2.给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
//class Solution {
//public:
//    void trace(TreeNode* root, vector<int>& v1)
//    {
//        if (root == NULL)
//        {
//            return;
//        }
//        else
//        {
//            trace(root->left, v1);
//            trace(root->right, v1);
//            v1.push_back(root->val);
//        }
//    }
//    vector<int> postorderTraversal(TreeNode* root)
//    {
//        vector<int> result;
//        trace(root, result);
//        return result;
//    }
//};
//3.给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
//class Solution {
//public:
//    void trace(TreeNode* root, vector<int>& v1)
//    {
//        if (root == NULL)
//        {
//            return;
//        }
//        else
//        {
//            trace(root->left, v1);
//            v1.push_back(root->val);
//            trace(root->right, v1);
//        }
//    }
//    vector<int> inorderTraversal(TreeNode* root)
//    {
//        vector<int> result;
//        trace(root, result);
//        return result;
//    }
//};
//4.给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root)
//    {
        //deque<TreeNode*> d1;
        //vector<vector<int>> v1;
        //if (root)
        //{
        //    d1.push_back(root);
        //}
        //while (d1.size())
        //{
        //    //等到没有入队后，意味着遍历已经结束了
        //    auto size = d1.size();
        //    vector<int> v2;
        //    for (int i = 0;i < size;i++)
        //    {
        //        TreeNode* x = d1.front();
        //        d1.pop_front();
        //        v2.push_back(x->val);
        //        if (x->left)
        //        {
        //            d1.push_back(x->left);
        //        }
        //        if (x->right)
        //        {
        //            d1.push_back(x->right);
        //        }

        //    }
        //    v1.push_back(v2);//一层结束
        //}
        //return v1;
//    }
//};
//5.给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//class Solution {
//public:
//    vector<vector<int>> levelOrderBottom(TreeNode* root)
//    {
        //deque<TreeNode*> d1;
        //vector<vector<int>> v1;
        //if (root)
        //{
        //    d1.push_back(root);
        //}
        //while (d1.size())
        //{
        //    //等到没有入队后，意味着遍历已经结束了
        //    auto size = d1.size();
        //    vector<int> v2;
        //    for (int i = 0;i < size;i++)
        //    {
        //        TreeNode* x = d1.front();
        //        d1.pop_front();
        //        v2.push_back(x->val);
        //        if (x->left)
        //        {
        //            d1.push_back(x->left);
        //        }
        //        if (x->right)
        //        {
        //            d1.push_back(x->right);
        //        }

        //    }
        //    v1.push_back(v2);//一层结束
        //}
        //reverse(v1.begin(), v1.end());
        //return v1;
//    }
//};
//6.给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//class Solution {
//public:
//    vector<int> rightSideView(TreeNode* root)
//    {
//        //层次遍历思想
        //vector<int> v1;
        //deque<TreeNode*> d1;
        //if (root)
        //{
        //    d1.push_back(root);
        //}
        //while (d1.size())
        //{
        //    auto size = d1.size();
        //    vector<int> v2;
        //    for (int i = 0;i < size;i++)
        //    {
        //        auto f = d1.front();
        //        d1.pop_front();
        //        v2.push_back(f->val);
        //        if (f->left)
        //        {
        //            d1.push_back(f->left);
        //        }
        //        if (f->right)
        //        {
        //            d1.push_back(f->right);
        //        }
        //    }
        //    v1.push_back(v2[size - 1]);
        //}
        //return v1;
//    }
//};
//7.给定一个非空二叉树的根节点 root, 以数组的形式返回每一层节点的平均值。与实际答案相差 10 - 5 以内的答案可以被接受。
//class Solution {
//public:
//    vector<double> averageOfLevels(TreeNode* root)
//    {
//        deque<TreeNode*> d1;
//        vector<double> v1;
//        if (root)
//        {
//            d1.push_back(root);
//        }
//        while (d1.size())
//        {
//            //等到没有入队后，意味着遍历已经结束了
//            auto size = d1.size();
//            vector<int> v2;
//            double sum = 0.0;
//            for (int i = 0;i < size;i++)
//            {
//                TreeNode* x = d1.front();
//                d1.pop_front();
//                v2.push_back(x->val);
//                sum += x->val;
//                if (x->left)
//                {
//                    d1.push_back(x->left);
//                }
//                if (x->right)
//                {
//                    d1.push_back(x->right);
//                }
//            }
//            sum = sum / size;
//            v1.push_back(sum);
//        }
//        return v1;
//    }
//};
//8.给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
//树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
//class Solution {
//public:
//    vector<vector<int>> levelOrder(Node* root)
//    {
//        vector<vector<int>> v1;
//        deque<Node*> d1;
//        if (root)
//        {
//            d1.push_back(root);
//        }
//        while (d1.size())
//        {
//            vector<int> v2;
//            int size = d1.size();
//            for (int i = 0;i < size;i++)
//            {
//                Node* x = d1.front();
//                d1.pop_front();
//                v2.push_back(x->val);
//                int y = x->children.size();
//                for (int i = 0;i < y;i++)
//                {
//                    if (x->children[i])
//                    {
//                        d1.push_back(x->children[i]);
//                    }
//                }
//            }
//            v1.push_back(v2);
//        }
//        return v1;
//    }
//};
//9.给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
//class Solution {
//public:
//    vector<int> largestValues(TreeNode* root)
//    {
//        deque<TreeNode*> d1;
//        vector<int> v1;
//        if (root)
//        {
//            d1.push_back(root);
//        }
//        while (d1.size())
//        {
//            //等到没有入队后，意味着遍历已经结束了
//            auto size = d1.size();
//            int max = d1.front()->val;
//            for (int i = 0;i < size;i++)
//            {
//                TreeNode* x = d1.front();
//                d1.pop_front();
//                max = max > x->val ? max : x->val;
//                if (x->left)
//                {
//                    d1.push_back(x->left);
//                }
//                if (x->right)
//                {
//                    d1.push_back(x->right);
//                }
//            }
//            v1.push_back(max);//一层结束
//        }
//        return v1;
//    }
//};
//10.给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
//struct Node {
//    int val;
//    Node* left;
//    Node* right;
//    Node* next;
//}
//填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
//初始状态下，所有 next 指针都被设置为 NULL。
//class Solution {
//public:
//    Node* connect(Node* root)
//    {
//        deque<Node*> d1;
//        Node* next = root;
//        if (root)
//        {
//            d1.push_back(root);
//        }
//        while (d1.size())
//        {
//            deque<Node*> d2;
//            auto x = d1.front();
//            d1.pop_front();
//            if (x->left)
//            {
//                d2.push_back(x->left);
//            }
//            if (x->right)
//            {
//                d2.push_back(x->right);
//            }
//            while (!d1.empty())
//            {
//                auto y = d1.front();
//                x->next = y;
//                d1.pop_front();
//                if (y->left)
//                {
//                    d2.push_back(y->left);
//                }
//                if (y->right)
//                {
//                    d2.push_back(y->right);
//                }
//                x = y;
//            }
//            if (d1.empty())
//            {
//                x->next = NULL;
//                d1 = d2;
//            }
//        }
//        return root;
//    }
//};
//11.给定一个二叉树：
//struct Node {
//    int val;
//    Node* left;
//    Node* right;
//    Node* next;
//}
//填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。
//初始状态下，所有 next 指针都被设置为 NULL 。
//class Solution {
//public:
//    Node* connect(Node* root)
//    {
//        deque<Node*> d1;
//        Node* next = root;
//        if (root)
//        {
//            d1.push_back(root);
//        }
//        while (d1.size())
//        {
//            deque<Node*> d2;
//            auto x = d1.front();
//            d1.pop_front();
//            if (x->left)
//            {
//                d2.push_back(x->left);
//            }
//            if (x->right)
//            {
//                d2.push_back(x->right);
//            }
//            while (!d1.empty())
//            {
//                auto y = d1.front();
//                x->next = y;
//                d1.pop_front();
//                if (y->left)
//                {
//                    d2.push_back(y->left);
//                }
//                if (y->right)
//                {
//                    d2.push_back(y->right);
//                }
//                x = y;
//            }
//            if (d1.empty())
//            {
//                x->next = NULL;
//                d1 = d2;
//            }
//        }
//        return root;
//    }
//};