//题目链接：
https://leetcode-cn.com/problems/sum-of-square-numbers/

//代码实现：

//方法一：sqrt
//时间复杂度 O(根号c) 最坏枚举n个数字
class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        //定下a ，枚举b
        for(long a = 0; a * a <= c; a ++)
        {
            double b = sqrt(c - a * a);
            if(b == (int)b)
            {
                return true;
            }
        }
        return false;
}
};

//方法二：双指针
//双指针，a = 0,b = 根号c
class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        long left = 0;
        long right = (int)sqrt(c);
        //这里小于等于很关键
        while(left <= right)
        {
            long sum = left * left + right * right;
            if(sum  == c)
            {
                return true;
            }
            else if(sum > c)
            {
                right--;
            }
            else 
            {
                left++;
            }
        }
        return false;
 }
};
