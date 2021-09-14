class Solution {
private:
    int countways(string &s, int index, int n, vector<int> &dp){
        
        if(index >= n) return 1;
        if(dp[index] != -1) return dp[index];
        if(s[index] == '0') return 0;

        if(index + 1 < n && s[index] == '1' || index + 1 < n && s[index] == '2' && s[index+1] <= '6'){
            return dp[index] = countways(s, index+1, n, dp) + countways(s, index+2, n, dp);
        }else{
            return dp[index] = countways(s, index+1, n, dp);
        }
    }    
    
public:
    int numDecodings(string s) {
        
        int n = s.length();
        
        if(s[0] == '0') return 0;
        if(n == 1) return 1;
        for(int i = 0; i < n-1; i++){
            if(s[i] == '0' && s[i+1] == '0') return 0;
        }
        
        vector<int> dp(n, -1);
        
        return countways(s, 0, n, dp);
    }
};