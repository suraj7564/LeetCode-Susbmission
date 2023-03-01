//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[N];
        for(auto x:edges){
            adj[x[0]].push_back({x[1], x[2]});
        }
        vector<int> dist(N, 1e7);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        while(!pq.empty()){
            auto cur = pq.top().second;
            int curD = pq.top().first;
            pq.pop();
            
            for(auto x:adj[cur]){
                if(curD + x.second < dist[x.first]){
                    dist[x.first] = curD + x.second;
                    pq.push({dist[x.first], x.first});
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i] == 1e7) dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends