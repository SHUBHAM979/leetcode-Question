class Solution {
public:
    int rec(int i, int state, vector<int> & prices, vector<vector<int>>& dp) {
        if(i == prices.size() ) return 0;
        int x = INT_MIN;
        if(dp[i][state] != -1) return dp[i][state];
        if(state == 0) {
            x = max(rec(i+1, 1, prices,dp) - prices[i] , rec(i+1,0,prices,dp));
        } else if( state ==1 ){
            x = max(rec(i+1, 2, prices,dp) + prices[i] , rec(i+1,1,prices,dp));
        } else if(state == 2) {
            x = rec(i+1, 0 , prices,dp);
        }
        return dp[i][state] =x;
       
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(3,-1));
        return rec(0,0, prices, dp);
    }
};