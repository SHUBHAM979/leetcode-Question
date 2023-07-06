class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     int j =0,i =0;
        int sum =0;
        int ans = INT_MAX;
        for( i=0; i< nums.size() ;i ++) {
            if(sum < target) {
                sum += nums[i];
                
            } 
            if(sum >= target){
                ans = min(ans, i-j+1);
                while(sum >=target) {
                    ans = min(ans, i-j+1);
                    sum -= nums[j];
                    j++;
                }
            }
        }
        
        if(j ==0 && sum < target) return 0;
        if(j == 0 ) return nums.size();
        return ans;
    }
};