//题目链接：
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

//代码实现：
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int left = 0 ,right = nums.size()-1;
        if(right == 0) return nums[0];

        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else if(nums[mid] < nums[right])
            {
                right = mid;
            }
            else if(nums[mid] == nums[right])
            {
                right--;
            }
        }
        return nums[left];

    }
};