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

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i<times.size(); i++){
            graph[times[i][0]-1].push_back({times[i][1]-1, times[i][2]});
        }
        
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        dist[k-1] = 0;
        q.push({0, k-1});
        
        while(!q.empty()){
            int u = q.top().second;
            q.pop();
            
            for(int i = 0; i<graph[u].size(); i++){
                int v = graph[u][i].first;
                int w = graph[u][i].second;
                
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    q.push({dist[v], v});
                }
            }
        }

        int res = *max_element(dist.begin(), dist.end());
        
        if(res == INT_MAX) return -1;
        return res;
    }
};
