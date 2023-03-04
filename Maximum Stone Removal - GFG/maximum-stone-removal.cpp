//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    map<pair<int, int>, int> mat;
    map<int, vector<vector<int>>> row, col;
    void dfs(int i, int j, int &cnt){
        cnt++;
        mat[{i, j}] = 0;
        for(auto x:row[i]){
            if(mat[{x[0], x[1]}] == 1){
                dfs(x[0], x[1], cnt);
            }
        }
        for(auto x:col[j]){
            if(mat[{x[0], x[1]}] == 1){
                dfs(x[0], x[1], cnt);
            }
        }
    }
    int maxRemove(vector<vector<int>>& stones, int n) {
        for(auto x:stones){
            row[x[0]].push_back(x);
            col[x[1]].push_back(x);
            mat[{x[0], x[1]}] = 1;
        }
        int ans = 0;
        for(auto x:row){
            for(auto y:x.second){
                if(mat[{y[0], y[1]}] == 1){
                    int cnt = 0;
                    dfs(y[0], y[1], cnt);
                    ans += cnt - 1;
                }
            }
        }
        for(auto x:col){
            for(auto y:x.second){
                if(mat[{y[0], y[1]}] == 1){
                    int cnt = 0;
                    dfs(y[0], y[1], cnt);
                    ans += cnt - 1;
                }
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
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends