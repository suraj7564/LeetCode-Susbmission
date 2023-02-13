//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int i, int n, int k, bool bought, int a[], vector<vector<vector<int>>>& dp){
        if(i >= n || k <= 0) return 0;
        if(dp[i][k][bought] != -1) return dp[i][k][bought];
        
        int ans = solve(i + 1, n, k, bought, a, dp);
        
        if(bought){
            ans = max(ans, solve(i + 1, n, k - 1, false, a, dp) + a[i]);
        }
        else{
            ans = max(ans, solve(i + 1, n, k, true, a, dp) - a[i]);
        }
        return dp[i][k][bought] = ans;
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(K+1, vector<int>(2, -1)));
        return solve(0, N, K, false, A, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends