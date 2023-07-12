class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n,0);
        vector<int> ans;
        vector<vector<int>> adj(n);
        
        for(int i =0;i <n; i++) {
            for(auto j : graph[i]) {
                adj[j].push_back(i);
                indegree[i]++;
            }
        }   
        
        queue<int> qu;
        for(int i=0; i<n ;i++) {
            if(indegree[i] == 0) {
                qu.push(i);
                cout << i <<" ";
            }
        }
        while(!qu.empty()) {
            int i = qu.front();
            ans.push_back(i);
            qu.pop();
            for(auto j : adj[i]) {
                indegree[j]--;
                if(indegree[j] == 0) qu.push(j);
            }
            
        }
        sort(ans.begin(), ans.end());
        return ans;
        
        
    }
    
  
    
};