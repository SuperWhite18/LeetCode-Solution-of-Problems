//题目链接：
https://leetcode-cn.com/problems/scramble-string/

//代码实现：
class Solution {
public:
    bool isScramble(string s1, string s2) {
    	if(s1 == s2) return true;
    	if(s1.size() != s2.size()) return false;

    	int n = s1.size();
    	vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(n+1, 0)));

    	// 先处理长度为 1 的情况
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < n; j++) {
    			if(s1[i] == s2[j])
    				f[i][j][1] = 1;
    		}
    	}

    	// 再处理其余长度情况
    	for(int len = 2; len <= n; len++) {
    		for(int i = 0; i+len <= n; i++) {
    			for(int j = 0; j+len <= n; j++) {
    				for(int k = 1; k < len; k++) {
    					bool a = f[i][j][k] && f[i+k][j+k][len-k];
    					bool b = f[i][j+len-k][k] && f[i+k][j][len-k];
    					if(a || b) 
    						f[i][j][len] = true;
    				}
    			}
    		}
    	}
    	return f[0][0][n];
    }
};

