//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class DSU{
    public:
    vector<int> p;
    DSU(){
        for(int i=0;i<=2000;i++){
            p.push_back(i);
        }
    }
    int get(int x){
        if(p[x] == x) return x;
        return p[x] = get(p[x]);
    }
    bool join(int x, int y){
        x = get(x);
        y = get(y);
        if(x != y){
            p[x] = y;
            return true;
        }
        return false;
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        if(edge.size() < n - 1) return -1;
        sort(edge.begin(), edge.end());
        DSU d;
        int ans = 0;
        for(auto x:edge){
            d.join(x[0], x[1]);
        }
        set<int> s1;
        for(int i=0;i<n;i++){
            s1.insert(d.get(i));
        }
        
        return s1.size() - 1;
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

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends