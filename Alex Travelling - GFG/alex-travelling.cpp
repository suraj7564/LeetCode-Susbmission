//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<vector<int>> adj[n+1];
        for(auto x:flights){
            adj[x[0]].push_back({x[1], x[2]});
        }
        
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            int d = pq.top().first, node = pq.top().second;
            pq.pop();
            for(auto x:adj[node]){
                if(dist[x[0]] > d + x[1]){
                    dist[x[0]] = d + x[1];
                    pq.push({dist[x[0]], x[0]});
                }
            }
        }
        int mx = 0;
        for(int i=1;i<=n;i++){
            if(mx >= 1e9) return -1;
            mx = max(mx, dist[i]);
        }
        return mx;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends