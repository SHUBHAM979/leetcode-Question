class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = nums[0] ;
        for(auto i : nums) {
            x = x^i;
        }
        x= x^nums[0];
        return x;
    }
};