//题目链接：
https://leetcode-cn.com/problems/merge-sorted-array/

//代码实现：
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        for (int i = 0; i != n; ++i) 
        {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};
