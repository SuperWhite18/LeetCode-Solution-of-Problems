//题目链接：
https://leetcode-cn.com/problems/increasing-order-search-tree/


//代码实现：
class Solution {
public:
    TreeNode* tail;
    TreeNode* increasingBST(TreeNode* root) 
    {
        auto dummy = new TreeNode(-1);
        tail = dummy;
        dfs(root);
        return dummy->right;
    }

    void dfs(TreeNode* root) 
    {
        if (!root) return;
        dfs(root->left);

        tail->right = root, root->left = NULL;
        tail = root;

        dfs(root->right);
    }
};