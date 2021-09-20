class Solution {
public:
    int compute(string &s, string &t, int n, int m, int x, int y, int count, vector<vector<int>> &dp){
        
        if(count == m) return 1;
        if(x >= n || y >=m) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        
        int b = 0, a = compute(s, t, n, m, x+1, y, count, dp);
        if(s[x] == t[y]) b = compute(s, t, n, m, x+1, y+1, count+1, dp);
        
        return dp[x][y] = a + b;
    }
    
    int numDistinct(string s, string t) {
        
        int n = s.length(), m = t.length();
        if(n < m) return 0;
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return compute(s, t, n, m, 0, 0, 0, dp);
    }
};