//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int get(int s, int n, int l, vector<pair<int,int>> adj[]){
        vector<int> dist(n, 1e9);
        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        while(!pq.empty()){
            int cur = pq.top().second;
            int curD = pq.top().first;
            pq.pop();
            for(auto x:adj[cur]){
                if(curD + x.second < dist[x.first]){
                    dist[x.first] = curD + x.second;
                    pq.push({dist[x.first], x.first});
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += dist[i] <= l;
        }
        return cnt;
    }
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
        
        vector<pair<int, int>> adj[n];
        for(auto x:edges){
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        
        int ans = 0, cur = n;
        for(int i=0;i<n;i++){
            int curAns = get(i, n, distanceThreshold, adj);
            if(curAns <= cur){
                cur = curAns;
                ans = i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends