class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto i : pre) {
            adj[i[1]].push_back(i[0]);
        }
        vector<int> indegree(n,0);
        for(int i=0; i< n; i++) {
            cout << i << " :";
            for(auto j : adj[i]){
                cout << j <<" ";
                indegree[j]++;
            }
            cout << endl;
        }
        queue<int> qu;
        for(int i=0; i< n; i++) {
            if(indegree[i] == 0) {
                cout << i;
                qu.push(i);
            }
        }
        
        vector<int> ans;
        while(!qu.empty()) {
            int  j = qu.front();
            ans.push_back(j);
            qu.pop();
            for(auto i : adj[j]) {
                indegree[i]--;
                if(indegree[i] == 0) qu.push(i);
            }
        }
        if(ans.size() != n) {
            return {};
        }
        return ans;
    }
};