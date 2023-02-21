class Solution {
public:
    int bs(vector<int>&nums) {
        int l=0, r = nums.size();
        while(l<=r) {
            int mid = l + (r-l)/2;
            if( (mid %2 ==0 && mid +1 <nums.size() && nums[mid] == nums[mid+1])||(mid %2 !=0 && mid -1 >=0 && nums[mid] == nums[mid-1])) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return nums[l];
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        return bs(nums);
    }
};