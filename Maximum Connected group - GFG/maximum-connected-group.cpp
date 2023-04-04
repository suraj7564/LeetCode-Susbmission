//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    map<int, int> componentSize;
    bool isValid(int i, int j, int n){
        if(i < 0 || j < 0 || i >= n || j >= n) return false;

        return true;
    }
    void dfs(int i, int j, int n, vector<vector<int>>& grid, int curColor){
        if(!isValid(i, j, n) || grid[i][j] == curColor || grid[i][j] == 0) return;
        grid[i][j] = curColor;
        componentSize[curColor]++;
        int d[] = {0, 1, 0, -1, 0};
        for(int k=0;k<4;k++){
            dfs(i + d[k], j + d[k + 1], n, grid, curColor);
        }
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        componentSize.clear();
        int n = grid.size();
        int curColor = 2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] != 1) continue;
                dfs(i, j, n, grid, curColor++);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] != 0) continue;
                int d[] = {0, 1, 0, -1, 0};
                int cur = 1;
                set<int> s1;
                for(int k=0;k<4;k++){
                    int x = i + d[k], y = j + d[k + 1];
                    if(isValid(x, y, n) && grid[x][y] != 0){
                        s1.insert(grid[x][y]);
                    }
                }
                for(auto x:s1){
                    cur += componentSize[x];
                }
                ans = max(ans, cur);
            }
        }
        if(ans == 0) ans = n * n;
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