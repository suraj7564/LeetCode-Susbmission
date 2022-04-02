// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int cur,int papa,vector<bool>& vis,int& time,vector<int>& low,
    vector<int>& disc,vector<bool>& isAp,vector<int> adj[]){
        vis[cur] = true;
        disc[cur] = low[cur] = ++time;
        int children = 0;
        
        for(auto x:adj[cur]){
            if(!vis[x]){
                children++;
                dfs(x,cur,vis,time,low,disc,isAp,adj);
                
                low[cur] = min(low[cur],low[x]);
                if(papa!=-1&&disc[cur]<=low[x]){
                    isAp[cur] = true;
                }
                
            }
            else if(x!=papa){
                low[cur] = min(low[cur],disc[x]);
            }
        }
        if(children>1&&papa==-1){
            isAp[cur] = true;
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        vector<bool> vis(V,false);
        vector<int> low(V,0),disc(V,0);
        vector<bool> isAp(V,false);
        int time = 0,papa = -1;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,papa,vis,time,low,disc,isAp,adj);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(isAp[i]){
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};

// { Driver Code Starts.

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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends