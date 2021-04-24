//题目链接：
https://leetcode-cn.com/problems/combination-sum-iv/


//代码实现：
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<unsigned> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; i ++ )
            for (auto j: nums)
                if (i >= j)
                    f[i] += f[i - j];
        return f[target];

    }
};