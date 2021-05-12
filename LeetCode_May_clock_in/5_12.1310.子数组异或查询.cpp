//题目链接：
https://leetcode-cn.com/problems/xor-queries-of-a-subarray/

//代码实现：
class Solution 
{
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        int n = arr.size();
        vector<int> preXOR(n + 1, 0); // “前缀和”初始化
        for(int i = 0; i < n; i ++) preXOR[i + 1] = arr[i] ^ preXOR[i]; // 得到“前缀和”
        vector<int> xorRange; // 区间异或结果
        for (auto & query : queries) 
        { // 得到区间左右边界
            int left = query[0], right = query[1];
            xorRange.push_back(preXOR[right + 1] ^ preXOR[left]); // 得到区间异或结果
        }
        return xorRange;
    }
};

