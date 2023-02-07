//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long int countWays(int n, int sum){
        // code here
        vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, 0));
        for(int i=1;i<=sum  && i<10;i++){
            dp[1][i] = 1;
        }
        int mod = 1e9 + 7;
        vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int i=2;i<=n;i++){
            for(int j=0;j<=sum;j++){
                for(int k=0;k<10;k++){
                    if(nums[k] <= j){
                        dp[i][j] = (dp[i][j]%mod + dp[i - 1][j - nums[k]]%mod)%mod;
                    }
                }
            }
        }
        if(dp[n][sum] == 0) return -1;
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, Sum;
        cin>>n>>Sum;
        
        Solution ob;
        cout<<ob.countWays(n, Sum)<<endl;
    }
    return 0;
}
// } Driver Code Ends