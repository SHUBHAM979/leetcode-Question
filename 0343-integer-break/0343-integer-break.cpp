class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        vector<int> dp(n+1,0);
        dp[2] = 1;
        dp[3] = 2;
      
        for(int i= 4; i<=n;i++) {
            int ans =0;
            for(int j=1; j<=i/2; j++) {
                int x, y;
                if(j <= 3) {
                   x = j;
                } else {
                    x= dp[j];
                }
                if(i-j <=3) {
                    y = i-j;
                } else{
                    y = dp[i-j];
                }
                ans = max(ans,x*y);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};