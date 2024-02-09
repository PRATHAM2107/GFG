//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkcycle(int u, vector<bool> &vis, vector<int>adj[],  int parent)
    {
        vis[u]=1;
        
        for(int v: adj[u])
        {
            if(v==parent) 
                continue;
            if(vis[v]) 
                return true;
            if(checkcycle(v, vis, adj, u))
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, 0);
        for(int i = 0; i<V; i++) 
        {
            if(vis[i] == false && checkcycle(i, vis, adj, -1))
                return true;
        }
       
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends