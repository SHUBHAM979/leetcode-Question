class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dp[n][n] ;
        for(int i=0; i<n ;i ++) {
            for(int j=0; j< n; j++) {
                dp[i][j] =0;
                
            }
        }
        
        for(auto i : edges) {
            dp[i[0]][i[1]] = i[2];
            dp[i[1]][i[0]] = i[2];
        }
        for(int i=0; i<n ;i ++) {
            for(int j=0; j< n; j++) {
                if(i == j){ dp[i][j]=0; continue; }
                if(dp[i][j] == 0) {
                    dp[i][j] =INT_MAX;
                }
                
            }
        }
        
        for(int i=0; i<n ;i ++) {
            for(int j=0; j< n; j++) {
                for(int k =0; k<n; k++) {
                    if(dp[j][i] !=INT_MAX && dp[i][k] !=INT_MAX){
                     
                        dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
                    }
                }
            }
        }
        for(int i=0; i<n ;i ++) {
            for(int j=0; j< n; j++) {
               cout << dp[i][j] <<" ";
                
            }
            cout <<"\n";
        }
        
        int ans = 0, maxcity =INT_MAX;
        
        for(int i=0; i<n; i++) {
            int count =0;
            for(int j = 0; j< n; j++) {
                if(i  == j) continue;
                if(dp[i][j] <= distanceThreshold) count++;
            }
            if(count <= maxcity) {
                ans =i;
                maxcity = count;
            }
            
        }
        
        return ans;
        
    }
};