//题目链接：
https://leetcode-cn.com/problems/range-sum-of-bst/

//代码实现：
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        int ans = 0;
        dfs(root,low,high,ans);
        return ans;
    }
    void dfs(TreeNode* rt,int low,int high,int& ans)
    {
        //根节点为空直接返回
        if(rt == NULL) return;
        //当前节点值位于区间，加到ans里
        if(rt->val >= low && rt->val <= high)
        {
            ans += rt->val;
        }
        //如果low小于当前节点值，则递归左子树
        if(rt->val > low)
        {
            dfs(rt->left,low,high,ans);
        }
        //如果high大于当前节点值，则递归右子树
        if(rt->val < high)
        {
            dfs(rt->right,low,high,ans);
        }
    }
};