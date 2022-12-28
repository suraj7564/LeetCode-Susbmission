// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int countBT(int h) { 
        // code here
        vector<long long> dp(h+5,0);
        long long mod = 1e9+7;
        dp[1] = 1;
        dp[2] = 3;
        for(int i=3;i<=h;i++){
            dp[i] = (((dp[i-1])%mod*(2LL*dp[i-2]%mod+dp[i-1]%mod)%mod)%mod)%mod;
        }
        return dp[h];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends