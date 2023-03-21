class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res =0;
        long long count;
        for(int i=0; i< nums.size(); i++) {
            count =0;
            if(nums[i] == 0) {
                while(i< nums.size() && nums[i] ==0) {
                    i++;
                    count++;
                }
                cout << count << " "; 
                res += count*(count+1)/2;
                
            }
        }
        return res;
    }
};