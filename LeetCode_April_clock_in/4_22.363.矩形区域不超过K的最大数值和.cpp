//题目链接：
https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/

//代码实现：
class Solution {
public:
    vector<vector<int>> s;

    int get(int x1, int y1, int x2, int y2) {
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        s = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
                s[i][j] = matrix[i - 1][j - 1] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

        int res = INT_MIN;
        for (int x1 = 1; x1 <= n; x1 ++ )
            for (int x2 = x1; x2 <= n; x2 ++ ) {
                set<int> S;
                S.insert(0);
                for (int y2 = 1; y2 <= m; y2 ++ ) {
                    int si = get(x1, 1, x2, y2);
                    auto it = S.lower_bound(si - k);
                    if (it != S.end()) res = max(res, si - *it);
                    S.insert(si);
                }
            }
        return res;
    }
};
