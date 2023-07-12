class Solution {
public:
    int minSum(int i, int j ,vector<vector<int>> tri) {
        if(i == tri.size()) return 0;
        
        return tri[i][j] + min( minSum(i+1,j,tri), minSum(i+1, j+1,tri));
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
       // return minSum(0,0,triangle);
        int n = triangle.size(), m = triangle[n-1].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,INT_MAX));
    
        dp[1][1] = triangle[0][0];
        for(int i = 2; i <=n;i++) {  
            for(int j = 1; j<=triangle[i-1].size(); j++) {
                
               dp[i][j] = triangle[i-1][j-1] + min(dp[i-1][j], dp[i-1][j-1]); 
                cout << i << " " << j  <<" "  << dp[i][j] <<"\n";
               
            }
        }
        int ans = INT_MAX;
        for(int j =1; j<= triangle[n-1].size(); j++) {
            ans = min(ans,dp[n][j]);
        }
        return ans;
        
    }
};