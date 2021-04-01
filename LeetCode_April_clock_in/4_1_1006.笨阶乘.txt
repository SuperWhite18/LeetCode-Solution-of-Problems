//题目链接：
https://leetcode-cn.com/problems/clumsy-factorial/


//代码实现：
class Solution {
public:
    int clumsy(int N) 
    {
        //维护一个栈，把不能确定的数据存入栈，确定了优先级最高以后
        //一旦可以确定结果，把数据从栈里取出来

        stack<int> stk;
        //从N开始枚举，直到1
        stk.push(N);
        N--;

        //用于控制加减乘除
        int index = 0;

        while(N > 0)
        {
            if(index % 4 == 0)
            {
                //乘
                stk.top() *= N;
            }
            else if(index % 4 == 1)
            {
                //除
                stk.top() /= N;
            }
            else if(index % 4 ==2)
            {
                //加
                stk.push(N);
            }
            else
            {
                //减
                stk.push(-N);
            }
            index++;
            N--;
        }
        //把栈中所有数字弹出求和
        int sum = 0;
        while(!stk.empty())
        {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};
