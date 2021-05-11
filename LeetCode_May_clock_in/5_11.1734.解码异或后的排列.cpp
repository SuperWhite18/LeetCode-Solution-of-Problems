//题目链接：
https://leetcode-cn.com/problems/decode-xored-permutation/

//代码实现：
class Solution {
public:
    vector<int> decode(vector<int>& encoded) 
    {
        int n = encoded.size();
        vector<int> perm(n+1);
        int ABCDE = 0;
        for(int i = 1;i <= n + 1; i++)
        {
            ABCDE ^= i;
        }
        int BCDE = 0;
        for(int i = 1;i < n; i+=2)
        {
            BCDE ^= encoded[i];
        }
        perm[0] = ABCDE ^ BCDE;

        for(int i = 1;i <= n; i++)
        {
            perm[i] = perm[i-1] ^ encoded[i-1];
        }
        return perm;

    }
};