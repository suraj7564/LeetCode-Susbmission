// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    long long countWays(int N) {
        // code here
        long long a[] = {1,3,4};
        
        vector<long long> dp(100001,0);
        
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        
        
        long long mod = 1e9+7;
        
        for(int i=5;i<=N;i++){
            dp[i] = (dp[i-4]%mod+dp[i-3]%mod+dp[i-1]%mod)%mod;
        }
        
        return dp[N];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countWays(N) << endl;
    }
    return 0;
}  // } Driver Code Ends