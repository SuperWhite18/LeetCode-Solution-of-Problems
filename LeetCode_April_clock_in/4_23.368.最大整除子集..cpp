//题目链接：
https://leetcode-cn.com/problems/largest-divisible-subset/

//代码实现：
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        //定义最大的整除子集
        vector<int> f(n);
        sort(nums.begin(),nums.end());
        //表示取到最大值的尾节点
        int k = 0;
        //从小到大枚举每一个数
        for(int i = 0; i < n; i ++)
        {
            f[i] = 1;
            for(int j = 0; j < i; j ++)
            {
                if(nums[i] % nums[j] == 0)
                   f[i] = max(f[i],f[j] + 1);
            }
            if(f[k] < f[i]) k = i;
        }

        vector<int> res;
        while(true)
        {
            res.push_back(nums[k]);
            if(f[k] == 1) break;
            for(int i = 0; i < k; i ++)
            {
                if(nums[k] % nums[i] == 0 && f[k] == f[i] + 1)
                {
                    k = i;
                    break;
                }
            }
        }
        return res;


    }
};