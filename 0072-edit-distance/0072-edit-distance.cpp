class Solution {
public:
    int rec(int i, int j,vector<vector<int>> & dp, string w1, string w2) {
        if(i <0) {
            return j+1;
        }
        if(j <0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(w1[i] == w2[j]) {
            return dp[i][j]= rec(i-1,j-1,dp,w1,w2);    
        }
        int x = 1+ rec( i, j-1,dp,w1,w2);
        x = min(x, 1+rec(i-1,j,dp,w1,w2));
        x = min(x, 1+ rec(i-1,j-1,dp,w1,w2));
        return dp[i][j] = x;
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> vt (word1.size(), vector<int>(word2.size() , -1));
        return rec(word1.size()-1, word2.size()-1, vt,word1,word2);
    }
};