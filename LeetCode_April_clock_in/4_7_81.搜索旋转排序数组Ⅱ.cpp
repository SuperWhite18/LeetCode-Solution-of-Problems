//题目链接：
https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/

//代码实现：
class Solution {
public:
    bool check(vector<int>& nums, int l, int r, int target) {
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return nums[r] == target;
    }

    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int n = nums.size() - 1;
        while (n > 0 && nums[n] == nums[0]) n -- ;
        if (nums[n] >= nums[0]) return check(nums, 0, n, target);
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }

        if (target >= nums[0]) return check(nums, 0, r - 1, target);
        return check(nums, r, n, target);
    }
};

