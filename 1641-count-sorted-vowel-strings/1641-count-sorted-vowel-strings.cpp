class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(5,1));
        int res =5;
        for(int i =2; i<= n; i++) {
            res=0;
            for(int  j=0; j<5; j++) {
                if(j == 0) dp[i][j] =1;
                else dp[i][j] = dp[i][j-1]+ dp[i-1][j];
                res += dp[i][j];
            }
        }
        return res;
        
    }
};