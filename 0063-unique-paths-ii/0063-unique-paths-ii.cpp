class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> t(n, vector<int>(m, -1));
        return solve(obstacleGrid, n-1, m-1, t);
    }

    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &t){

        if(i < 0 || j < 0)
            return 0;
        if(grid[i][j] == 1)
            return 0;
        if(i == 0 && j == 0)
            return 1;
        if(t[i][j] != -1)
            return t[i][j];
        
        int up = solve(grid, i-1, j, t);
        int left = solve(grid, i, j-1, t);

        return t[i][j] = up + left;
    }
};