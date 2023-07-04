class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<vector<int>> adj(vals.size(), vector<int>());
        for(auto i : edges) {
            adj[i[0]].push_back(vals[i[1]]);
            adj[i[1]].push_back(vals[i[0]]);
        }
        cout << "helo";
        vector<int> ans = vals;
        for(int i=0; i< vals.size(); i++) {
             sort(adj[i].begin(), adj[i].end(), greater<int>());
             for(int j=0; j < adj[i].size() && j<k ; j++) {
                 ans[i] = max(ans[i], ans[i]+adj[i][j]);
             }
        }
        int maxans = INT_MIN; 
        for(auto i : ans) {
            maxans = max(maxans, i);
        }
        return maxans;
        
    }
};