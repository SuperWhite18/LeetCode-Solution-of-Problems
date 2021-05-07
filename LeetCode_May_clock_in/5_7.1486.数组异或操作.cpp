//题目链接：
https://leetcode-cn.com/problems/xor-operation-in-an-array/

//代码实现：
class Solution {
public:
    int xorOperation(int n, int start) 
    {
        int ans = 0;
        for (int i = 0; i < n; ++i) 
        {
            ans ^= (start + i * 2);
        }
        return ans;
    }
};