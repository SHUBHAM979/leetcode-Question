class Solution {
public:
  
    int df(int i, int prev,  vector<int>& nums, vector<vector<int >> &dp) {
        if(i==nums.size()) {
            
            return 0;
        }
        if(dp[i][prev+1] !=-1) return dp[i][prev+1];
        
          int y =0,len=0;
       
        if( prev ==-1 ||  nums[i] > nums[prev] ){
               y =1+ df(i+1, i, nums,dp ) ;                          
        } 
    len = df(i+1,prev,nums,dp);
        
        return dp[i][prev+1] = max(len,y);;
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        
        return df(0, -1,nums,dp);
        
    }
};