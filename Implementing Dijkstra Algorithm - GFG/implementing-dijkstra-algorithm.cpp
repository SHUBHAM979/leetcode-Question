//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
        // vector<int> dist(V);
        // for(int  i =0; i < V; i++) dist[i] = 1e9;
        
        // dist[S] =0;
        // pq.push({0,S});
        // while(!pq.empty()) {
        //     int dis = pq.top().first;
        //     int node = pq.top().second;
        //     pq.pop();
        //  
        // }
        // return dist;
        
        //
        
        vector<int> dist(V, INT_MAX);
        dist[S] =0;
        pq.push({0,S});
        while(!pq.empty()) {
            pair<int,int> node= pq.top();
            pq.pop();
            int dis = node.first;
            // for(auto i : adj[node.second]) {
            //     int edw = i[1];
            //      int adjnode = i[0];
            //     if(dist + i[1] < dist[adjnode ] ) {
            //         dist[adjnode] = dist + i[1];
            //         pq.push({dist[i[0]], i[0]});
            //     }
            // }
            
              for(auto i : adj[node.second]) {
                int edw = i[1];
                int adjnode = i[0];
                if(dis + edw < dist[adjnode]) {
                    dist[adjnode] = dis+edw;
                    pq.push({dist[adjnode], adjnode});
                }
            }
            
        }
        return dist;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends