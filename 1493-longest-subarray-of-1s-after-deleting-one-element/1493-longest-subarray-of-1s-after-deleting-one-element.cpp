class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count1 =0;
        map<int , pair<int,int>> mp;
        int countl=0;
        for(int i=0; i< nums.size() ; i++) {
            if(nums[i] == 0) {
                mp[i].first = countl;
                countl=0;
            } else {
                countl++;
                count1++;
            }
        }
    
       
          int countr =0;
        for(int i=nums.size()-1; i>=0 ; i--) {
            if(nums[i] == 0) {
                mp[i].second = countr;
                countr=0;
            } else {
                countr++;
                
            }
            
        }
        int sum = 0;
        for(int i =0; i< nums.size(); i++) {
            if(nums[i] == 0) {
                sum = max(mp[i].first + mp[i].second, sum);   
            }
            
        }
        cout << count1;
        if(count1 == nums.size()) return count1-1;
        return sum;
        
    }
};