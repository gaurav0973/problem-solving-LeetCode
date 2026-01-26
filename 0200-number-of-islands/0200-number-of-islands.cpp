class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool isValidLoaction(vector<vector<char>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        return (i >= 0 && i <= n-1 && j >= 0 && j <= m-1);
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(!isValidLoaction(grid, i, j))
            return;
        
        if(grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        for(auto &d : dir){
            int new_i = i + d[0];
            int new_j = j + d[1];
            dfs(grid, new_i, new_j);
        }
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};