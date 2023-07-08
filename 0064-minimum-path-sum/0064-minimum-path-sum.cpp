class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& grid ,vector<vector<int>> &dp) {
        if(i == grid.size()-1 && j == grid[0].size() -1) return grid[i][j];
        if(i == grid.size() || j == grid[0].size()) return 10e6;
        //cout << i << j <<"\n";
        if(dp[i][j]!=-1) return dp[i][j];
        int x = grid[i][j] + rec(i+1, j,grid,dp);
        dp[i][j] = min(x, grid[i][j] + rec(i, j+1, grid,dp));
        return dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return rec(0,0,grid, dp);
        
    }
};