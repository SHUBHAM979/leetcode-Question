class Solution {
    void rec(int i, int n, int k, vector<int>& subans,vector<vector<int>>& ans) {
        
        if(subans.size() == k) {
            ans.push_back(subans);
            return;
        }
        if(i>n) return;
        
           subans.push_back(i);
        rec(i+1,n,k,subans,ans);
        subans.pop_back();
        rec(i+1,n,k,subans, ans);
     
        
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> sub;
        rec(1,n,k, sub, ans);
        return ans;
    }
};