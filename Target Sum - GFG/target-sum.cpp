//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&a ,int t) {
        //Your code here
        vector<int> dp(20001, 0);
        int total = 0;
        dp[0] = 1;
        for(int i=0;i<a.size();i++){
            total += a[i];
            for(int j=20000;j>=a[i];j--){
                dp[j] += dp[j - a[i]];
            }
        }
        int ans = 0;
        for(int i=0;i<=20000;i++){
            if(dp[i]){
                int cur = 2 * i - total;
                if(cur == t) ans += dp[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends