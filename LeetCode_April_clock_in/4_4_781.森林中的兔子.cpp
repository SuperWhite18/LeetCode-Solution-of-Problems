//题目链接：
https://leetcode-cn.com/problems/rabbits-in-forest/

//代码实现：
class Solution {
public:
    int numRabbits(vector<int>& answers) 
    {
        sort(answers.begin(),answers.end());

        int n = answers.size();
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            int cnt = answers[i];
            ans += cnt+1;
            int k = cnt;
            while(k-- && i+1 < n && answers[i] == answers[i+1])
            i++;
        }
        return ans;


    }
};