//题目链接：
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/

//代码实现：
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int l = 0,r = nums.size()-1;
        while(l<r)
        {
            int mid = l + r + 1>>1;
            if(nums[l] <= nums[mid])
            {
                l = mid;
            }
            else
            {
                r = mid -1;
            }
        }
        return r + 1 < nums.size() ? nums[r+1] : nums[0];
    }
};