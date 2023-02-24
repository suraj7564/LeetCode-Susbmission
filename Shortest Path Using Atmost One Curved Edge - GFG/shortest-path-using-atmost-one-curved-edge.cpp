//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> getDist(int a, int n, vector<vector<int>> adj[]){
        vector<int> dist(n + 1, 1e9 + 5);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[a] = 0;
        pq.push({0, a});
        while(!pq.empty()){
            int curDist = pq.top().first, curNode = pq.top().second;
            pq.pop();
            for(auto &x:adj[curNode]){
                if(curDist + x[1] < dist[x[0]]){
                    dist[x[0]] = curDist + x[1];
                    pq.push({dist[x[0]], x[0]});
                }
            }
        }
        return dist;
    }
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj[n + 1];
        for(auto &x:edges){
            adj[x[0]].push_back({x[1], x[2], x[3]});
            adj[x[1]].push_back({x[0], x[2], x[3]});
        }
        
        vector<int> aDist = getDist(a, n, adj);
        vector<int> bDist = getDist(b, n, adj);
        
        int ans = aDist[b];
        
        
        for(auto &x:edges){
            ans = min(ans, aDist[x[0]] + bDist[x[1]] + x[3]);
            ans = min(ans, aDist[x[1]] + bDist[x[0]] + x[3]);
        }
        
        if(ans >= 1e9 + 5) ans = -1;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends