//题目链接：
https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&&tqId=11154&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking


//代码实现：
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) 
    {
        if(array.empty() || array[0].empty()) return false;
        int i = 0,j = array[0].size() - 1;
        while(i < array.size() && j >= 0)
        {
            if(array[i][j] == target) return true;
            if(array[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};