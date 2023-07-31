class Solution {
    int cut(int i, int j, int start, int end,vector<int>& cuts,vector<vector<int>> &dp) {
        if(i>j) return 0;
        int mini = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k=0; k<cuts.size(); k++) {
            if(cuts[k] <= cuts[j] && cuts[k] >=cuts[i]) {
                mini = min(mini, end-start + cut(i,k-1, start,cuts[k],cuts,dp) + cut(k+1 ,j,cuts[k], end ,cuts,dp));
            }
        }
        if(mini ==INT_MAX) mini =0;
        return dp[i][j] = mini;
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        sort(cuts.begin(),cuts.end());
        return cut(0,cuts.size()-1,0, n,cuts,dp);
    }
};