//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int solve(int i, int bought, int k, vector<int>& p, vector<vector<vector<int>>>& dp){
    if(i == p.size() || k == 0) return 0;
    if(dp[i][k][bought] != -1) return dp[i][k][bought];
    
    int ans = solve(i + 1, bought, k, p, dp);
    
    if(bought){
        ans = max(ans, solve(i + 1, 0, k - 1, p, dp) + p[i]);
    }
    else{
        ans = max(ans, solve(i + 1, 1, k, p, dp) - p[i]);
    }
    
    return dp[i][k][bought] = ans;
}
int maxProfit(vector<int>& p){
    int n = p.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
    return solve(0, 0, 2, p, dp);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends