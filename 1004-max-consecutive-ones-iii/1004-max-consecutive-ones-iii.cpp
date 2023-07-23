class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count =0 , ans =0;
        queue<int> qu;
        for(int i =0; i< nums.size(); i++) {
            if(nums[i] == 1) count++;
            else if( nums[i] == 0 && k > 0) {
                count++;
                qu.push(i);
                k--;
            } else {
                ans =max(count,ans);
                if(!qu.empty()) {
                count = i - qu.front() ;
                qu.pop();
                qu.push(i);} else count =0;
            }
        }
        ans = max(count,ans);
        return ans;
    }
};