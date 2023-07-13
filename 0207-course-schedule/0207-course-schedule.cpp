class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        if(numCourses == 0) return true;
       
        queue<int> qu;
        
        vector<vector<int>> adj(numCourses, vector<int>());
        
            for(auto i : pre) {
                adj[i[1]].push_back(i[0]);
            }
        vector<int> indegree(numCourses,0);
        for(int i=0; i< numCourses; i++) {
            for(auto j : adj[i]) {
                indegree[j]++;
            }
        }
        
        for(int i=0; i< numCourses; i++) {
            if(indegree[i] == 0) qu.push(i);
        }
        vector<int> topo;
        
        while(!qu.empty()) {
            int i = qu.front();
            qu.pop();
            topo.push_back(i);
            for(auto j : adj[i] ) {
               indegree[j]--;
                if(indegree[j] == 0) qu.push(j);
            }
        }
        
        if(topo.size() == numCourses) return true;
    
     
        return false;;
        
        
        
    }
};