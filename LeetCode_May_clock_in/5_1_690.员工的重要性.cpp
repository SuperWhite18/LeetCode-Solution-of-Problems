//题目链接：
https://leetcode-cn.com/problems/employee-importance/

//代码实现：
class Solution {
public:
    unordered_map<int,Employee*> hash;
    int getImportance(vector<Employee*> employees, int id) 
    {
        for(auto& p : employees) hash[p->id] = p;
        return dfs(id);
    }

    int dfs(int id)
    {
        auto p  =hash[id];
        int res = p -> importance;
        for(auto son : p->subordinates)
            res += dfs(son);
        return res;
    }
};