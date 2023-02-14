//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
vector<int> dp(100001, -1);
class Solution {
  public:
    int mod = 1e9 + 7;
    long long int topDown(int n) {
        // code here
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (topDown(n - 1)%mod + topDown(n - 2)%mod)%mod;
    }
    long long int bottomUp(int n) {
        // code here
        if(n <= 1) return n;
        vector<long long> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = (dp[i - 1]%mod + dp[i - 2]%mod)%mod;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 100001; i++) dp[i] = -1;
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends