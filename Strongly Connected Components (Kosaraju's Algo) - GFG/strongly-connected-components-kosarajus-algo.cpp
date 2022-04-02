// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int cur,vector<bool>& vis,stack<int>& s1,vector<int> adj[]){
	    vis[cur] = true;
	    
	    for(auto x:adj[cur]){
	        if(!vis[x]){
	            dfs(x,vis,s1,adj);
	        }
	    }
	    
	    s1.push(cur);
	}
	
	void dfs1(int cur,vector<bool>& vis,vector<int> adj[]){
	    vis[cur] = false;
	    
	    for(auto x:adj[cur]){
	        if(vis[x]){
	            dfs1(x,vis,adj);
	        }
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> vis(V,false);
        stack<int> s1;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,s1,adj);
            }
        }
    
        vector<int> adj1[V];
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                adj1[x].push_back(i);
            }
        }
        
        int ans = 0;
        while(!s1.empty()){
            int t = s1.top();
            //cout<<t<<" ";
            s1.pop();
            if(vis[t]){
                dfs1(t,vis,adj1);
                ans++;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

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