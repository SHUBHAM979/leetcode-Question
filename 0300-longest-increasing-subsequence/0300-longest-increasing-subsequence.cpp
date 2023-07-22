class Solution {
    // int  longest(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
    //     if(i == nums.size()) return 0;
    //     if(dp[i][prev+1] != -1) return dp[i][prev+1];
    //     if(prev == -1 || nums[i] > nums[prev]) {
    //         return dp[i][prev+1] =  max(1 + longest(i+1, i, nums, dp), longest(i+1, prev, nums,dp));
    //     }
    //     return dp[i][prev+1] = longest(i+1,prev, nums,dp);
    // }
    
    
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        // return longest(0,-1, nums, dp);
         vector<int> dp(nums.size(),1);
        for(int i =0; i< nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i]>nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int ans = 0;
        for(int i =0; i< nums.size(); i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};