//题目链接：
https://leetcode-cn.com/problems/brick-wall/

//代码实现：
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> gapmp;
        int maxvalue = 0;
        for (auto &wallline : wall)
        {
            int distance = 0;
            for (int i = 0; i < wallline.size()-1; i++)
            {
                distance+=wallline[i];
                gapmp[distance]++;
                maxvalue = max(maxvalue,gapmp[distance]);
            }
        }
        if(gapmp.size()==0)
            return wall.size();
        return wall.size() - maxvalue;
    }
};
