class Solution {
public:
    void rec(int i, vector<int> ds, vector<vector<int>> & ans,int sum , vector<int>& candidates, int target) {
        if(sum == target) {
            ans.push_back(ds);
            
            return;
        }
        if(sum > target || i == candidates.size()) return;
        
        
        rec(i+1, ds, ans, sum , candidates,target);
        ds.push_back(candidates[i]);
        rec(i, ds, ans, sum + candidates[i], candidates,target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        rec(0,vector<int>(), ans, 0, candidates, target);
        return ans;
        
    }
};