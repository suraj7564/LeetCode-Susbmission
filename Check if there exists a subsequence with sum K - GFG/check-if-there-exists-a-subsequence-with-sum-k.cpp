//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int i, int k, vector<int>& arr, vector<vector<int>>& dp){
        if(k == 0) return 1;
        if(i == arr.size() || k < 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        
        int ans = solve(i + 1, k, arr, dp);
        ans |= solve(i + 1, k - arr[i], arr, dp);
        
        return dp[i][k] = ans;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, arr, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends