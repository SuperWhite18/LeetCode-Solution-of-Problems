//题目链接：
https://leetcode-cn.com/problems/remove-element/

//代码实现：
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int index=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            nums[index++]=nums[i];
            
        }
        return index;

    }
};