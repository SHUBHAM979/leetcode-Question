class Solution {
public:
    void dfs(int i,map<int,bool>& mp, vector<int>& vis ,vector<vector<int>>& graph, bool& flag) {
        vis[i] =1;
        for(auto j : graph[i]) {
            if(!vis[j]) {
                mp[j] = !mp[i]; 
                        dfs(j, mp, vis, graph,flag);
                        
                    } else {
                        if(mp[j] == mp[i]) { 
                           // cout << x << " ." << j << mp[j]<< " " << mp[1] << mp[3];
                            flag =  false; }
                    }
                }
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        map<int, bool > mp;
        vector<int> vis(graph.size(), 0);
        for(int i =0; i< graph.size(); i++) {
            if(vis[i]) continue;
            // queue<int> qu;
            // qu.push(i);
            bool flag =true;
            mp[i] = true;
            dfs(i,mp,vis,graph, flag);
            if(flag == false) return false;
//             while(!qu.empty()) {
                
//                 int x = qu.front();
//                 qu.pop();
//                 vis[x] =1;
//                flag = !mp[x];
//                 for(auto j : graph[x]) {
//                     if(!vis[j]) {
//                         qu.push(j);
//                         mp[j] =flag; 
//                     } else {
//                         if(mp[j] != flag) { 
//                             cout << x << " ." << j << mp[j]<< " " << mp[1] << mp[3];
//                             return false; }
//                     }
//                 }
                
           // }
            
        }
        return true;
        
    }
};