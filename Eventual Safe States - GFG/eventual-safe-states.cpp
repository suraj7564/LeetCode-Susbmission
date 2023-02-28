//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> inDegree(V);
        vector<int> adj1[V];
	    for(int i=0;i<V;i++){
	        for(auto x:adj[i]){
	            inDegree[i]++;
	            adj1[x].push_back(i);
	        }
	    }
	    queue<int> q;
	    vector<int> ans;
	    for(int i=0;i<V;i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        auto t = q.front();
	        q.pop();
	        ans.push_back(t);
	        for(auto x:adj1[t]){
	            inDegree[x]--;
	            if(inDegree[x] == 0){
	                q.push(x);
	            }
	        }
	    }
	    sort(ans.begin(), ans.end());
	    return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends