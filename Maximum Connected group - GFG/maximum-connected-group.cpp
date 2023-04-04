//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class DSU{
    public:
    vector<int> p;
    vector<int> rank;
    DSU(int n){
        for(int i=0;i<=n*n;i++){
            p.push_back(i);
            rank.push_back(1);
        }
    }
    void connect(int a, int b){
        a = find(a), b = find(b);
        if(a != b){
            if(rank[a] >= rank[b]){
                rank[a] += rank[b];
                p[b] = a;
            }
            else{
                rank[b] += rank[a];
                p[a] = b;
            }
        }
    }
    int find(int a){
        if(p[a] == a) return a;
        return p[a] = find(p[a]);
    }
};

class Solution {
  public:
    bool isValid(int i, int j, int n){
        if(i < 0 || j < 0 || i >= n || j >= n) return false;

        return true;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int d[] = {0, 1, 0, -1, 0};
        DSU ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    for(int k=0;k<4;k++){
                        int x = i + d[k], y = j + d[k + 1];
                        if(isValid(x, y, n) && grid[x][y] == 1){
                            ds.connect(i * n + j, x * n + y);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    set<int> s1;
                    for(int k=0;k<4;k++){
                        int x = i + d[k], y = j + d[k + 1];
                        if(isValid(x, y, n) && grid[x][y] == 1){
                            s1.insert(ds.find(n * x + y));
                        }
                    }
                    int cur = 0;
                    for(auto x:s1){
                        cur += ds.rank[x];
                    }
                    ans = max(ans, cur + 1);
                }
            }
        }
        if(ans == 0) return n*n;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends