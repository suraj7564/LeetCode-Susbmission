//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int cur, int p, vector<int> adj[], vector<int>& vis){
        for(auto x:adj[cur]){
            if(vis[x] == 0){
                vis[x] = -1 * vis[cur];
                if(check(x, cur, adj, vis)){
                    return true;
                }
            }
            else if(x != p && vis[x] == vis[cur]){
                return true;
            }
        }
        return false;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V, 0);
	    for(int i=0;i<V;i++){
	        if(vis[i] == 0){
	            vis[i] = 1;
	            if(check(i, -1, adj, vis)) return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends