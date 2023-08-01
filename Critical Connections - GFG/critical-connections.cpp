//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	int DFS(int node, vector<int> adj[], vector<int>&disc, vector<int>&low, vector<vector<int>>&ans, int &timer, int parent)
    {
       if(disc[node]!=-1)
       return disc[node];
       
       timer++;
       disc[node]=low[node]=timer;
       
       for(int i=0; i<adj[node].size(); i++)
       {
           int neighbour=adj[node][i];
           
           if(neighbour==parent)
           continue;
           
           low[node] = min(low[node], DFS(neighbour,adj,disc,low,ans,timer,node));
           
           //bridge condition
           if(low[neighbour]>disc[node])
           {
               if(node>neighbour)
               ans.push_back({neighbour,node});
               else
               ans.push_back({node,neighbour});
           }
       }
        
        return low[node];
    }

 vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
     // Code here
    vector<vector<int>>ans;
    vector<int>disc(V,-1);
    vector<int>low(V,-1);
    int timer=-1, parent=-1;
    DFS(0,adj,disc,low,ans,timer,parent);
    sort(ans.begin(), ans.end());
     
     return ans;
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
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends