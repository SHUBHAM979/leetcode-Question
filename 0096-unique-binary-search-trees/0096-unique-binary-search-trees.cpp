class Solution {
    vector<int> dp;
    
public:
    Solution() : dp(1000001,-1) {
        
    }
    
    int numTrees(int n) {
        if(n  <= 1) return 1;
        int ans = 0;
        if(dp[n] != -1) {
            return dp[n];
        }
        for(int i=1; i<=n ;i++) {
            ans += numTrees(i-1) * numTrees(n- i);
        }
        return dp[n] = ans;
    }

};