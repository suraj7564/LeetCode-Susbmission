//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        vector<pair<int, int>> dp(n, {1, 1});
        int mx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i] > arr[j])
                    if(dp[i].first < dp[j].first + 1){
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    }
                    else if(dp[i].first == dp[j].first + 1){
                        dp[i].second += dp[j].second;
                    }
            }
            mx = max(mx, dp[i].first);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(dp[i].first == mx){
                cnt += dp[i].second;
            }
            //cout<<dp[i].first<<" "<<dp[i].second<<endl;
        }
        //cout<<endl;
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends