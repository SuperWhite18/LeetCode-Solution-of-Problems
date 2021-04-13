//题目链接：
https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/


//代码实现：
class Solution {
private:
int result = INT_MAX;
TreeNode* pre;
void traversal(TreeNode* cur) {
    if (cur == NULL) return;
    traversal(cur->left);   // 左
    if (pre != NULL){       // 中
        result = min(result, cur->val - pre->val);
    }
    pre = cur; // 记录前一个
    traversal(cur->right);  // 右
}
public:
    int minDiffInBST(TreeNode* root) {
        traversal(root);
        return result;
    }
};

