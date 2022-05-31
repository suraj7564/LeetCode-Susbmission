// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s) {
        //code here
        int n = s.length();
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j = i+l-1;
                if(s[i]!=s[j]) dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                else{
                    if(l==2) dp[i][j] = 2;
                    else dp[i][j] = dp[i+1][j-1]+2;
                }
            }
        }
        return dp[0][n-1];
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends