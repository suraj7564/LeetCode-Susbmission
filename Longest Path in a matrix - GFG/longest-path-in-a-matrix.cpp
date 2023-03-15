//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int n, m;
    int solve(int i, int j, int val, vector<vector<int>>& a, vector<vector<int>>& dp){
        if(i < 0 || j < 0 || i >= n || j >= m || a[i][j] <= val){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int d = solve(i + 1, j, a[i][j], a, dp);
        int u = solve(i - 1, j, a[i][j], a, dp);
        int l = solve(i, j - 1, a[i][j], a, dp);
        int r = solve(i, j + 1, a[i][j], a, dp);
        
        return dp[i][j] = 1 + max({l, r, u, d});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Code here
        n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans, solve(i, j, -1, matrix, dp));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends