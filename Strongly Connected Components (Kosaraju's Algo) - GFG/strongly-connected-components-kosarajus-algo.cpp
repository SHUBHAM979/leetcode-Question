//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    vector<vector<int>> ans;
	public:
	//Function to find number of strongly connected components in the graph.
    void topodfs(int i, stack<int> &st ,vector<int> &vis, vector<vector<int>>& adj ) {
        vis[i] = 1;
        for(auto it : adj[i]) {
            if(!vis[it]) {
                topodfs(it, st,vis, adj);   
            }
        }
        st.push(i);
    }
    
    void revdfs(int i , vector<int> &vis, vector<int> as,vector<vector<int>>& adj ) {
        vis[i] =1;
        as.push_back(i);
        for(auto it : adj[i]) {
            if(!vis[it]) {
                revdfs(it, vis, as,adj);   
            }
        }
        
    }
    
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0; i< V; i++) {
            if(!vis[i]) {
                topodfs(i,st,vis,adj);
            }
        }
        vector<vector<int>> transpose(V,vector<int>());
        for(int  i=0; i<V; i++) {
            vis[i] = 0;
            for(auto it : adj[i]) {
                transpose[it].push_back(i);
            }
        }
        
        while(!st.empty()) {
            int j = st.top();
            st.pop();
            if(!vis[j])  {
                vector<int> as;
                revdfs(j, vis, as, transpose) ;
                ans.push_back(as);
            };
        }
        return ans.size();
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends