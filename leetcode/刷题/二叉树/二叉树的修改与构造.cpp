//1.给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
//class Solution {
//public:
//    void fanzhuan(TreeNode*& root)
//    {
//        if (root->left == nullptr && root->right == nullptr)
//        {
//            return;
//        }
//        else
//        {
//            TreeNode* temp = root->left;
//            root->left = root->right;
//            root->right = temp;
//            if (root->right) { fanzhuan(root->right); }
//            if (root->left) { fanzhuan(root->left); }
//        }
//    }
//    TreeNode* invertTree(TreeNode* root)
//    {
//        if (root == nullptr)
//        {
//            return root;
//        }
//        else
//        {
//            fanzhuan(root);
//            return root;
//        }
//    }
//};
//2.给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
//class Solution {
//public:
//    unordered_map<int, int> pos;
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//        int n = inorder.size();
//        for (int i = 0; i < n; i++) {
//            pos[inorder[i]] = i;     //记录中序遍历的根节点位置
//        }
//        return dfs(inorder, postorder, 0, n - 1, 0, n - 1);
//    }
//    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
//        if (il > ir) return nullptr;
//        int k = pos[postorder[pr]];   //中序遍历根节点位置
//        TreeNode* root = new TreeNode(postorder[pr]); //创建根节点
//        root->left = dfs(inorder, postorder, il, k - 1, pl, pl + k - 1 - il);
//        root->right = dfs(inorder, postorder, k + 1, ir, pl + k - 1 - il + 1, pr - 1);
//        return root;
//    }
//};
//3.给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建 :
//创建一个根节点，其值为 nums 中的最大值。
//递归地在最大值 左边 的 子数组前缀上 构建左子树。
//递归地在最大值 右边 的 子数组后缀上 构建右子树。
//返回 nums 构建的 最大二叉树 。
//class Solution {
//public:
//    TreeNode* gouzao(int left, int right, vector<int>& nums)
//    {
//        if (left > right)
//        {
//            return nullptr;
//        }
//        int best = left;
//        for (int i = left + 1; i <= right; ++i) {
//            if (nums[i] > nums[best])
//            {
//                best = i;
//            }
//        }
//        TreeNode* node = new TreeNode(nums[best]);
//        node->left = gouzao(left, best - 1, nums);
//        node->right = gouzao(best + 1, right, nums);
//        return node;
//    }
//    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
//    {
//        return gouzao(0, nums.size() - 1, nums);
//    }
//};
//4.给你两棵二叉树： root1 和 root2 。
//想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。
//合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。返回合并后的二叉树。
//注意 : 合并过程必须从两个树的根节点开始
//class Solution {
//public:
//    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
//    {
//        TreeNode* root = new TreeNode;
//        if (root1 && root2)
//        {
//            root->val = root1->val + root2->val;
//            root->left = mergeTrees(root1->left, root2->left);
//            root->right = mergeTrees(root1->right, root2->right);
//        }
//        else if (root1 && !root2)
//        {
//            root = root1;
//            return root;
//        }
//        else if (!root1 && root2)
//        {
//            root = root2;
//            return root;
//        }
//        else
//        {
//            root = nullptr;
//            return root;
//        }
//        return root;
//    }
//};
