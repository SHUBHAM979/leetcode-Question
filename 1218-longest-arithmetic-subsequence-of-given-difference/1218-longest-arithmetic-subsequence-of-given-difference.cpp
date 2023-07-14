class Solution {
public:
    // dp solution givng TLE
    // int rec(int i , int j, vector<int>& arr, int d ,vector<vector<int>>& dp) {
    //     if(arr.size() == i) return 0;\
    //     if(dp[i+1][j+1] != -1) return dp[i+1][j+1];
    //     if(j == -1) {
    //         return  dp[i+1][j+1] =max(1+ rec(i+1, i, arr, d,dp), rec(i+1, j, arr, d,dp));
    //     }
    //     if(arr[i]- arr[j] == d) {
    //         return dp[i+1][j+1] = 1+ rec(i+1, i, arr, d,dp);
    //     }
    //     return dp[i+1][j+1] = rec(i+1,j, arr,d,dp);
    // }
    
    
    int longestSubsequence(vector<int>& arr, int diff) {
        // vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1,-1));
        // return rec(0, -1, arr, difference, dp);
        unordered_map<int,int> mp;
        vector<int> dp(arr.size(),1);
        for(int i =0; i< arr.size(); i++) {
            if(mp.find(arr[i] - diff) != mp.end()) {
                dp[i] += dp[mp[arr[i]-diff]];
            }
            mp[arr[i]] = i;
        }
        int  maxi =INT_MIN;
        for(auto i : dp) {
            maxi = max(i, maxi);
        }
        return maxi;
        
    }
}; 