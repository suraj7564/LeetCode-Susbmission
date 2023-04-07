//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int n=s.length();
        int dp[n+1][n+1];
        for(int i=0;i<n;i++){
            dp[0][i]=dp[1][i]=1;
        }
        int l=0,r=0;
        for(int i=2;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(s[j-1]==s[j-i]&&dp[i-2][j-1]==1){
                    dp[i][j]=1;
                    if((r-l+1)<(i)){
                        l=j-i;
                        r=j-1;
                    }
                }
                else dp[i][j]=0;
            }
        }
        return s.substr(l,r-l+1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends