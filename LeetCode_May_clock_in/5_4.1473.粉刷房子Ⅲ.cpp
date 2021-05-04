//题目链接：
https://leetcode-cn.com/problems/paint-house-iii/

//代码实现：
class Solution {
public:
    int minCost(vector<int>& hs, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 1e8;
        vector<vector<vector<int>>> f(m, vector<vector<int>>(target + 1, vector<int>(n + 1, INF)));
        if (hs[0]) f[0][1][hs[0]] = 0;
        else {
            for (int i = 1; i <= n; i ++ )
                f[0][1][i] = cost[0][i - 1];
        }

        for (int i = 1; i < m; i ++ )
            for (int j = 1; j <= target; j ++ ) {
                if (hs[i]) {
                    int k = hs[i];
                    for (int u = 1; u <= n; u ++ )
                        if (u == k)
                            f[i][j][k] = min(f[i][j][k], f[i - 1][j][u]);
                        else
                            f[i][j][k] = min(f[i][j][k], f[i - 1][j - 1][u]);
                } else {
                    for (int k = 1; k <= n; k ++ )
                        for (int u = 1; u <= n; u ++ )
                            if (u == k)
                                f[i][j][k] = min(f[i][j][k], f[i - 1][j][u] + cost[i][k - 1]);
                            else
                                f[i][j][k] = min(f[i][j][k], f[i - 1][j - 1][u] + cost[i][k - 1]);
                }
            }
        int res = INF;
        for (int i = 1; i <= n; i ++ ) res = min(res, f[m - 1][target][i]);
        if (res == INF) res = -1;
        return res;
    }
};

