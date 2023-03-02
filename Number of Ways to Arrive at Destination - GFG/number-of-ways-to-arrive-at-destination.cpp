//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<long long, long long>> adj[n];
        for(auto x:roads){
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        vector<long long> dist(n, 1e14), path(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[0] = 0, path[0] = 1;
        pq.push({0, 0});
        int mod = 1e9 + 7;
        while(!pq.empty()){
            int cur = pq.top().second;
            long long curD = pq.top().first;
            pq.pop();
            for(auto x:adj[cur]){
                if(curD + x.second < dist[x.first]){
                    dist[x.first] = curD + x.second;
                    path[x.first] = path[cur]%mod;
                    pq.push({dist[x.first], x.first});
                }
                else if(curD + x.second == dist[x.first]){
                    path[x.first] = (path[x.first]%mod + path[cur]%mod)%mod;
                }
            }
        }
        return path[n - 1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends