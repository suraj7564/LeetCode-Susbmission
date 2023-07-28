//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int cur, vector<int> adj[], vector<int>& vis, vector<int>& mark){
        vis[cur] = 1;
        mark[cur] = 1;
        for(auto x:adj[cur]){
            if(vis[x] == 0){
                if(dfs(x, adj, vis, mark)) return true;
            }
            else if(mark[x]){
                return true;
            }
        }
        mark[cur] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V), mark(V);
        for(int i=0;i<V;i++){
            if(vis[i]) continue;
            if(dfs(i, adj, vis, mark)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends