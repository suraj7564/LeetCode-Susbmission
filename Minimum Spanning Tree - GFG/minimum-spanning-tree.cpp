//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU{
    public:
    vector<int> p;
    DSU(){
        for(int i=0;i<=2000;i++){
            p.push_back(i);
        }
    }
    int get(int x){
        if(p[x] == x) return x;
        return p[x] = get(p[x]);
    }
    bool join(int x, int y){
        x = get(x);
        y = get(y);
        if(x != y){
            p[x] = y;
            return true;
        }
        return false;
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>> edg;
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                edg.push_back({x[1], x[0], i});
            }
        }
        sort(edg.begin(), edg.end());
        DSU d;
        int ans = 0;
        for(auto x:edg){
            if(d.join(x[1], x[2])){
                ans += x[0];
            }
        }
        return ans;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends