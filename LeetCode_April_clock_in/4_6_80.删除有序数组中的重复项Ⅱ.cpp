//题目链接：


//代码实现：
//解法一：
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) { // 特殊判断，如果nums长度小于2，直接输出长度n即可
            return n;
        }
        int slow = 2, fast = 2; // 因为上面已经做过特殊判别，所以这里快慢指针从2开始
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) { // 因为题目要求最多两个数相同，所以这么判断
            // 如果nums[slow - 2] == nums[fast]，代表已经有两个数相等，此时nums[fast]
            // 对应的数值不能放进结果之中。反之，如果nums[slow - 2] != nums[fast]，
            // 那么nums[fast]可以放进nums[slow]中，并且slow++，记录结果的长度。
                nums[slow] = nums[fast]; 
                slow++;
            }
            fast++; // 不管怎么样，快指针都是要向前遍历各个元素的
        }
        return slow; // 返回结果的长度，即slow
    }
};

//解法二：
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; // 左指针初始化
        for (int num : nums) { // num当右指针
            if (i < 2 || nums[i - 2] < num) { // i < 2是特殊判断，nums[i - 2] < num
            // 是因为题目要求相同元素不能超过两个。之所以可以用小于号判断，是因为数组是有序的
                nums[i] = num; // 相当于上面官方解法的nums[slow] = nums[fast];
                i++; // 相当于上面官方解法的slow++;，即左指针移动
            }
        }
        return i; // 输出长度，即相当于上面题解的slow
    }
};


