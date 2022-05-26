// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        if(r>n) return 0;
        r = min(r,n-r);
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(r+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(i,r);j++){
                if(j==0||j==i) dp[i][j] = 1;
                else{
                    dp[i][j] = (dp[i-1][j-1]%mod+dp[i-1][j]%mod)%mod;
                }
            }
        }
        return dp[n][r];
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends