//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n = costs.size(), k = costs[0].size();
        if(n > 1 && k == 1) return -1;
        vector<vector<int>> dp(n + 1, vector<int>(k));
        dp[1] = costs[0];
        for(int i=1;i<n;i++){
            int mn = 1e9;
            vector<int> sufMin(k);
            for(int j=k-1;j>=0;j--){
                sufMin[j] = mn;
                mn = min(mn, dp[i][j]);
            }
            mn = 1e9;
            for(int j=0;j<k;j++){
                dp[i + 1][j] = costs[i][j] + min(mn, sufMin[j]);
                mn = min(mn, dp[i][j]);
            }
        }
        int ans = 1e9;
        for(int j=0;j<k;j++){
            ans = min(ans, dp[n][j]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends