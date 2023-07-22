class Solution {
    
    double pro(int i, int j, int k, int n,vector<vector<vector<double>>> &dp ) {
        if(i<0 || i>=n || j<0|| j>=n) { cout << i << " " << j << " " << k << endl; return 0; }
        else if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(k == 0) return 1;
        
        // cout << i << " " << j << " " << k << endl;
        double total =  pro(i+1,j+2,k-1,n,dp) + pro(i+2,j+1,k-1,n,dp) + pro(i+2,j-1,k-1,n,dp) + pro(i+1,j-2,k-1,n,dp) + pro(i-2,j+1,k-1,n,dp) + pro(i-1,j+2,k-1,n,dp) + pro(i-2,j-1,k-1,n,dp) + pro(i-1,j-2,k-1,n,dp);
        total /= 8.0;
        dp[i][j][k] = total;
        cout << total << endl;
        return total;
    }
    
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n , vector<vector<double>>(n,vector<double>(k+1, double(-1))));
        return pro(row,column,k,n,dp);
    }
};