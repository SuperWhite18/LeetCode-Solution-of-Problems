//题目链接：
https://leetcode-cn.com/problems/single-number-ii/


//代码实现：
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();//为数组的长度
        sort(nums.begin(),nums.end());//对数组进行排序
        int pre = nums[0];//上一个出现的数字
        int count = 1;//count记录某个数字出现的次数
        //遍历一次数组,对每个数字进行计数,如果计数的结果为1,只出现了一次,直接返回这个值
        for(int i = 1;i < n; i++){
            //如果当前数字与上一个数字相同,计数加一
            if(nums[i] == pre){
                count++;
            }else{
                //如果当前数字与上一个不相同,说明是一个新的数字
                //先检查上一个数字的计数是否为1,如果是的话,直接返回上一个数字,否则继续运算
                if(count == 1){
                    return pre;
                }
                //对于一个新的数字,我们计数归为1
                //把当前数字作为上一个数字,更新pre,以便后面的数字进行比较
                count = 1;
                pre = nums[i];
            }
        }
        return pre;
    }
};

