class Solution {
private:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &checkGrid, bool &tag, int x, int y, int n, int m){
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
    
            grid[x][y] = 0;
            if(checkGrid[x][y] == 0) tag = false;
            
            dfs(grid, checkGrid, tag, x+1, y, n, m);
            dfs(grid, checkGrid, tag, x-1, y, n, m);
            dfs(grid, checkGrid, tag, x, y+1, n, m);
            dfs(grid, checkGrid, tag, x, y-1, n, m);
        }
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int n = grid1.size();
        int m = grid1[0].size();
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid2[i][j] == 1){
                    bool tag = true;
                    dfs(grid2, grid1, tag, i, j, n, m);
                    if(tag) count++;
                }
            }
        }
        return count;
    }
};
