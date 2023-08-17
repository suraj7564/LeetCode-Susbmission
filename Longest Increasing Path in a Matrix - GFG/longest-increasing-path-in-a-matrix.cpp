//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dp[1001][1001];
    int dfs(vector<vector<int>> &matrix, int i, int j, int pre) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || pre >= matrix[i][j])
            return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int p = matrix[i][j];
        matrix[i][j] = -1;
        int l = dfs(matrix, i, j - 1, p);
        int r = dfs(matrix, i, j + 1, p);
        int u = dfs(matrix, i - 1, j, p);
        int d = dfs(matrix, i + 1, j, p);
        matrix[i][j] = p;
        return dp[i][j] = max({l, r, u, d}) + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {

        // Code here
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = -1;
            }
        }
        int maxVal = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                maxVal = max(maxVal, dfs(matrix, i, j, -1));
        return maxVal;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends