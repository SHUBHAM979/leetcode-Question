class Solution {
public:
    void rec(int i, vector<int> subsol, set<vector<int>>& nodup, vector<int>  nums) {
        if(i == nums.size()) {
            nodup.insert(subsol);
            return;
        }
        rec(i+1,subsol, nodup, nums);
        subsol.push_back(nums[i]);
        rec(i+1,subsol, nodup, nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> nodup;
        sort(nums.begin(),nums.end());
        rec(0,vector<int>(), nodup, nums);
        vector<vector<int>> ans;
        for(auto i : nodup) {
            ans.push_back(i);
        }
        return ans;
    }
};