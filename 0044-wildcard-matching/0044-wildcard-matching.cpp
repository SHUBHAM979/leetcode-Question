class Solution {
public:
    bool matching(int i , int j, string s, string p,  vector<vector<int>>& dp) {
        if( i == s.length() && j == p.length()) {
            return true;
        }
        if((i >= s.length() && j <p.length()) &&  (p[j] !='*') ) {
            return false;
        }
        if(j >= p.length() && i < s.length()) {
            return false;
        }
        if(dp[i][j] != -1) {
            if(dp[i][j] == 1) return true;
            else return false;
        }
      
        if(s[i] == p[j] || p[j] =='?' ) {
             dp[i][j] =  matching(i+1, j+1, s, p,dp );
        } else if (p[j] == '*') {
                if( i== s.length()) {
                        dp[i][j]  = matching(i, j+1,s,p, dp); 
                  
                } else 
                       dp[i][j]  =( matching(i, j+1,s,p, dp) ||  matching(i+1, j,s,p,dp)  );
                  
                
            
        } else
            dp[i][j] = 0;
        
        return dp[i][j];
        
        
    }
    
    bool isMatch(string s, string p) {
        if(p.length() == 0) return s.length() ==0;
        // vector<vector<int>> dp(s.length() +1, vector<int>(p.length()+1, -1));
        // return matching(0,0,s,p, dp);
        vector<vector<int>> dp(s.length() +1, vector<int>(p.length()+1, 0));
        
         dp[0][0] = true;
        for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
            dp[0][j + 1] = true;
        }
        
        for(int i=1; i<= s.length(); i++) {
            for(int j=1; j <= p.length(); j++) {
               if(p[j-1] == '*') {
                   dp[i][j] = dp[i][j-1] || dp[i-1][j];
               } else {
                   dp[i][j] =(s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
               }
            }
        }
        
        return dp[s.length()][p.length()];
        
        
    }
 

};