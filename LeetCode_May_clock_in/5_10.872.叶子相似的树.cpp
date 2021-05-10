//题目链接：
https://leetcode-cn.com/problems/leaf-similar-trees/

//代码实现：
class Solution {
public:

    void dfs(TreeNode* node,vector<int>& seq)
    {
        if(!node->left && !node->right)
        {
            seq.push_back(node->val);
        }
        else
        {
            if(node->left)
            {
                dfs(node->left,seq);
            }
            if(node->right)
            {
                dfs(node->right,seq);
            }
            
        }

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> seq1;
        if(root1)
        {
            dfs(root1,seq1);
        }
        vector<int> seq2;
        if(root2)
        {
            dfs(root2,seq2);
        }
        return seq1 == seq2;
             
    }

};