class Solution {
    int ans =0;
public:
    int rec(int i, int j, string s, string t, vector<vector<int>> & dp) {
        if(j>=t.length()){
            return 1;
        }
        if(i>=s.length()) return 0;
        if(dp[i][j] !=-1) return dp[i][j];
        int x =0;
        if(s[i] == t[j])
             return dp[i][j] = rec(i+1, j+1, s,t,dp)+rec(i+1, j,s,t,dp);
        return dp[i][j] = rec(i+1, j,s,t,dp); 
    }
    
    
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(),-1));
        
        return rec(0,0 ,s,t, dp);
    }
};