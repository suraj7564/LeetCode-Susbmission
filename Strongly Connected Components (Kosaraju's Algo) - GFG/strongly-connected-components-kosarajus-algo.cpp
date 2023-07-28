//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int cur, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
	    vis[cur] = 1;
	    for(auto x:adj[cur]){
	        if(vis[x] == 0){
	            dfs(x, adj, vis, st);
	        }
	    }
	    st.push(cur);
	}
	void dfs(int cur, vector<vector<int>>& adj, vector<int>& vis){
	    vis[cur] = 0;
	    for(auto x:adj[cur]){
	        if(vis[x] == 1){
	            dfs(x, adj, vis);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st;
        vector<int> vis(V, 0);
        
        vector<vector<int>> adj1(V);
        for(int i=0;i<V;i++){
            if(vis[i] == 0){
                dfs(i, adj, vis, st);
            }
            for(auto x:adj[i]){
                adj1[x].push_back(i);
            }
        }
        int ans = 0;
        while(!st.empty()){
            auto t = st.top();
            st.pop();
            if(vis[t] == 1){
                ans++;
                dfs(t, adj1, vis);
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