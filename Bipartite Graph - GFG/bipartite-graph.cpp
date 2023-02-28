//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int cur, vector<int> adj[], vector<int>& color){
        
        for(auto x:adj[cur]){
            if(color[x] == 0){
                color[x] = -color[cur];
                if(dfs(x, adj, color)) return true;
            }
            else if(color[x] == color[cur]) return true;
        }
        return false;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V, 0);
	    for(int i=0;i<V;i++){
	        if(color[i] == 0){
	            color[i] = 1;
	            if(dfs(i, adj, color)) return false;
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