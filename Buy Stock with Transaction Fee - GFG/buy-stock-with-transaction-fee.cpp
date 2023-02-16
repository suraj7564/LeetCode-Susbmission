//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(int i, int bought, long long fee, vector<long long>& a, vector<vector<long long>>& dp){
        if(i >= a.size()) return 0;
        if(dp[i][bought] != -1) return dp[i][bought];
        
        long long ans = solve(i + 1, bought, fee, a, dp);
        
        if(bought){
            ans = max(ans, solve(i + 1, 0, fee, a, dp) + a[i] - fee);
        }
        else{
            ans = max(ans, solve(i + 1, 1, fee, a, dp) - a[i]);
        }
        
        return dp[i][bought] = ans;
    }
    long long maximumProfit(vector<long long>& a, int n, int fee) {
        // Code here
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, 0, (long long)fee, a, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends