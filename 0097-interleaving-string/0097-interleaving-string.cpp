class Solution {
public:
    bool check(int i, int j, int k,string &s1, string& s2, string &s3, vector<vector<int>>& dp) {
        if(k == s3.length()) return true;
        cout << i <<" " << j << " " << k <<"\n";
        if(dp[i][j] != -1) return dp[i][j];
        if(i < s1.length() && j< s2.length() && s1[i] == s3[k] && s2[j] == s3[k]) {
            return dp[i][j] = check(i+1,j,k+1,s1,s2,s3,dp) || check(i,j+1,k+1,s1,s2,s3,dp);
        }
        if(i < s1.length() && s1[i] == s3[k]) {
            return dp[i][j] = check(i+1, j, k+1,s1,s2,s3,dp);
        }
        if(j < s2.length() && s2[j] == s3[k]) {
            return dp[i][j] =check(i, j+1, k+1,s1,s2,s3,dp);
        }
        return dp[i][j] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        // vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        // return check(0,0,0, s1,s2,s3,dp);
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
        for(int i=0; i<= s1.length(); i++) {
            for(int j=0; j<=s2.length();j++) {
                if(i==0 && j==0)
                dp[i][j] = true;
            else if(i == 0)
                dp[i][j] = ( dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                dp[i][j] = ( dp[i-1][j] && s1[i-1] == s3[i+j-1]);
            else
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1] ) || (dp[i][j-1] && s2[j-1] == s3[i+j-1] );
            }
        }
        return dp[s1.length()][s2.length()];
    }
};