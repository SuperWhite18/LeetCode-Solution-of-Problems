//题目链接：
https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/

//代码实现：
class Solution {
public:
bool check(vector<int>& w, int D, int x) 
{
        int cnt = 1;
        for (int i = 0, s = 0; i < w.size(); i ++ ) 
        {
            if (w[i] > x) return false;
            if (s + w[i] > x) 
            {
                cnt ++ ;
                s = 0;
            }
            s += w[i];
        }
        return cnt <= D;
    }

    int shipWithinDays(vector<int>& weights, int D) 
    {
        int l = 0, r = 500 * 50000;
        while (l < r) 
        {
            int mid = l + r >> 1;
            if (check(weights, D, mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }


};