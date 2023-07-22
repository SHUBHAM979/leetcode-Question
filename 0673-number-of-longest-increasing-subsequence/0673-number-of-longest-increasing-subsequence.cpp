class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> len(nums.size(), 1), count(nums.size(),1);
        for(int i =0; i< nums.size(); i++) {
            for(int j =0; j< i; j++) {
                if(nums[i] > nums[j]) {
                    if(len[i] < len[j]+1) {
                        len[i] = len[j]+1;
                        count[i]=0;
                    } 
                    if(len[i] == len[j]+1) {
                        count[i]+= count[j];
                    }
                }
            }
        }
        int ans = 0, res =0;
        for(int i =0; i< nums.size(); i++) {
            ans = max(ans, len[i]);
        }
        for(int i=0; i< nums.size(); i++) {
            if(ans == len[i]) res += count[i];
        }
        return res;
        
        
        
    }
};