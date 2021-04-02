//题目链接：
https://leetcode-cn.com/problems/volume-of-histogram-lcci/

//思路分析：
1.总体积减去柱子的体积就是水的容量
2.用双指针思想
3.先计算每一层雨水和柱子的总体积，三层相加，得到整体的体积vol
4.然后计算柱子的总体积sum，就是区间长度
5.再用vol-sum即是雨水的体积
6.注意细节：while(left <= right)  每一层的vol=right-left+1

//代码实现：
class Solution {
public:
    int trap(vector<int>& height) 
    {
        //计算柱子的体积
        int sum = accumulate ( height.begin(), height.end(), 0);
        int vol = 0;
        int high = 1;
        int size = height.size();
        //双指针
        int left = 0;
        int right = height.size() - 1;

        while (left <= right)
        {
            while(left <= right && height[left] < high)
            {
                left++;
            }
            while(left <= right && height[right] < high)
            {
                right--;
            }
            //算每一行的容量累加
            vol += right - left + 1;
            //更新high高度 再上一层
            high++;
        }
        return vol - sum;
    }
};