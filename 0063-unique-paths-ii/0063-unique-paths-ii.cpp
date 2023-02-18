class Solution {
    int res =0;
public:
    int dfs(int i, int j,int n, int m, vector<vector<int>>& grid ,  vector<vector<int>>& dp) {
       if(i>= n || j>=m) return 0;
         if(grid[i][j] == 1) return 0;
        if(i == n-1 && j == m-1)  {
            return 1;
        }
       
        if(dp[i][j] != -1) return dp[i][j];
        int x =dfs( i+1, j , n, m, grid, dp);
        int y = dfs(i, j+1,n, m, grid, dp);
        return dp[i][j] = x+y;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n  = grid.size(), m= grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        return dfs(0,0,n,m, grid, dp);
    }
};