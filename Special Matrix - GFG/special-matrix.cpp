//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    // Code here
	    int mod = 1e9 + 7;
	    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	    for(auto x:blocked_cells){
	        dp[x[0]][x[1]] = -1;
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(dp[i][j] == -1){
	                dp[i][j] = 0;
	                continue;
	            }
	            if(i == 1 && j == 1){
	                dp[i][j] = 1;
	            }
	            else{
	                dp[i][j] = (dp[i - 1][j]%mod + dp[i][j - 1]%mod)%mod;
	            }
	        }
	    }
	    return dp[n][m];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends