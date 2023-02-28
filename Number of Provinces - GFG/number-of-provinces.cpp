//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int cur, vector<vector<int>>& adj, vector<int>& vis){
        vis[cur] = 1;
        for(int i=0;i<adj[cur].size();i++){
            if(vis[i] == 0 && adj[cur][i] == 1){
                dfs(i, adj, vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int cnt = 0;
        vector<int> vis(V);
        for(int i=0;i<V;i++){
            if(vis[i] == 0){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends