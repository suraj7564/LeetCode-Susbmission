//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<vector<int>> adj[n];
        for(auto x:flights){
            adj[x[0]].push_back({x[1], x[2]});
        }
        queue<vector<int>> q;
        q.push({0, src, 0});
        vector<int> dist(n, 10000000);
        dist[src] = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int curDist = t[0], node = t[1], stops = t[2];
            if(stops > k) continue;
            for(auto x:adj[node]){
                if(curDist + x[1] < dist[x[0]]){
                    dist[x[0]] = curDist + x[1];
                    q.push({dist[x[0]], x[0], stops + 1});
                }
            }
            
        }
        if(dist[dst] >= 1e7) return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends