//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void dfs(int i,stack<int>& st,vector<int> & vis,vector<int> adj[] ) {
	    vis[i] = 1;
	    for(auto it :adj[i]) {
	        if(!vis[it]) {
	            dfs(it, st,vis, adj);
	        }
	    }
	    st.push(i);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indeg(V,0) , vis(V,0);
	    stack<int> st;
	    for(int i=0; i < V; i++) {
	        if(!vis[i]) {
	            dfs(i,st,vis, adj);
	        }
	    }
	    vector<int> jsd;
	    while(!st.empty()) {
	        jsd.push_back(st.top());
	        st.pop();
	    }
	    return jsd;
	   // for(int i =0; i< V; i++)
    // 	    for(auto it : adj[i])  {
    // 	        indeg[it]++;
    // 	    }
    // 	queue<int> qu;
    // 	for(int i=0; i< V ; i++) {
    // 	    if(indeg[i] == 0) {
    // 	        qu.push(i);
    // 	    }
    // 	}
    // 	vector<int> ans;
    // 	while(!qu.empty()) {
    // 	    int x = qu.front();
    // 	    qu.pop();
    // 	    ans.push_back(x);
    // 	    for(i : adj[x]) {
    // 	        indeg[i]--;
    // 	        if(indeg[i]==0) qu.push(i);
    // 	    }
    // 	}
    // 	return ans;
	    
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends