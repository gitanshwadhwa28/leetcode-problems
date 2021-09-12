class Solution {
public:
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