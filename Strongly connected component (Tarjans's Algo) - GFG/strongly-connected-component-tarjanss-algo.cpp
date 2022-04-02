// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> ans;
    void dfs(int cur,int& time,vector<int>& low,vector<int>& disc,vector<bool>& vis,
    stack<int>& s1,vector<int> adj[]){
        
        disc[cur] = low[cur] = ++time;
	    vis[cur] = true;
	    s1.push(cur);
	    
	    for(auto x:adj[cur]){
	        if(disc[x]==-1){
	            dfs(x,time,low,disc,vis,s1,adj);
	            low[cur] = min(low[cur],low[x]);
	        }
	        else if(vis[x]){
	            low[cur] = min(low[cur],disc[x]);
	        }
	    }
	    
	    if(low[cur]==disc[cur]){
	        vector<int> temp;
	        while(!s1.empty()&&s1.top()!=cur){
	            temp.push_back(s1.top());
	            vis[s1.top()] = false;
	            s1.pop();
	        }
	        if(!s1.empty())
	        {
	            temp.push_back(s1.top());
	            vis[s1.top()] = false;
	            s1.pop();
	            
	        }
	        ans.push_back(temp);
	    }
	}
	
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        ans.clear();
        vector<bool> vis(V,false);
        vector<int> low(V,-1),disc(V,-1);
        stack<int> s1;
        int time = 0;
        for(int i=0;i<V;i++){
            if(disc[i]==-1){
                dfs(i,time,low,disc,vis,s1,adj);
            }
        }
        
        for(auto &x:ans){
             sort(x.begin(),x.end());
        }
        sort(ans.begin(),ans.end());
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends