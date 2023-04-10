//1.给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
//注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。
//class Solution {
//public:
//    TreeNode* rookie = new TreeNode();
//    void diedai(TreeNode*& root, int val)
//    {
//        rookie->val = val;
//        if (!root)
//        {
//            return;
//        }
//        if (root->val < val && !root->right)
//        {
//            root->right = rookie;
//            return;
//        }
//        else if (root->val > val && !root->left)
//        {
//            root->left = rookie;
//            return;
//        }
//        else
//        {
//            if (root->val > val)
//            {
//                diedai(root->left, val);
//            }
//            if (root->val < val)
//            {
//                diedai(root->right, val);
//            }
//        }
//    }
//    TreeNode* insertIntoBST(TreeNode* root, int val)
//    {
//        if (!root)
//        {
//            rookie->val = val;
//            return rookie;
//        }
//        diedai(root, val);
//        return root;
//    }
//};
//2.给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
//一般来说，删除节点可分为两个步骤：
//首先找到需要删除的节点；
////如果找到了，删除它。
//class Solution {
//public:
//    TreeNode* deleteNode(TreeNode* root, int key)
//    {
//        if (root == nullptr)    return nullptr;
//        if (key > root->val)    root->right = deleteNode(root->right, key);     // 去右子树删除
//        else if (key < root->val)    root->left = deleteNode(root->left, key);  // 去左子树删除
//        else    // 当前节点就是要删除的节点
//        {
//            if (!root->left)   return root->right; // 情况1，欲删除节点无左子
//            if (!root->right)  return root->left;  // 情况2，欲删除节点无右子
//            TreeNode* node = root->right;           // 情况3，欲删除节点左右子都有 
//            while (node->left)          // 寻找欲删除节点右子树的最左节点
//                node = node->left;
//            node->left = root->left;    // 将欲删除节点的左子树成为其右子树的最左节点的左子树
//            root = root->right;         // 欲删除节点的右子顶替其位置，节点被删除
//        }
//        return root;
//    }
//};
//3.给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。修剪树 
//不应该 改变保留在树中的元素的相对结构(即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 唯一的答案 。
//所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。
//class Solution {
//public:
//    TreeNode* trimBST(TreeNode* root, int low, int high) {
//        if (root == nullptr) return nullptr;//如果是空，直接返回
//        if (root->val < low)
//        {
//            //根节点的值小于最低值，删除根节点和它的左节点
//            TreeNode* right = trimBST(root->right, low, high); // 寻找符合区间[low, high]的节点
//            return right;
//        }
//        if (root->val > high)
//        {
//            //删除根节点及其右结点
//            TreeNode* left = trimBST(root->left, low, high); // 寻找符合区间[low, high]的节点
//            return left;
//        }
//        root->left = trimBST(root->left, low, high); // root->left接入符合条件的左孩子
//        root->right = trimBST(root->right, low, high); // root->right接入符合条件的右孩子
//        return root;
//    }
//};
//4.给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
//高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
//class Solution {
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums)
//    {
//        TreeNode* root = new TreeNode();
//        //每个子树以数组的中间位置的节点为
//        if (nums.size() == 1)
//        {
//            root->val = nums[0];
//            return root;
//        }
//        if (nums.size() == 2)
//        {
//            TreeNode* root1 = new TreeNode(nums[1]);
//            root->val = nums[0];
//            root1->left = root;//左右无所谓
//            return root1;
//        }
//        int mid = nums.size() / 2;
//        root->val = nums[mid];
//        vector<int> v1(nums.begin(), nums.begin() + mid);
//        vector<int> v2(nums.begin() + mid + 1, nums.end());
//        root->left = sortedArrayToBST(v1);
//        root->right = sortedArrayToBST(v2);
//        return root;
//    }
//};