//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int i, int j, vector<vector<int>>& t, vector<vector<int>>& dp){
        if(i == t.size() - 1) return t[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = solve(i + 1, j, t, dp);
        ans = min(ans, solve(i + 1, j + 1, t, dp));
        
        return dp[i][j] = t[i][j] + ans;
    }
    int minimizeSum(int n, vector<vector<int>>& t) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, t, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends