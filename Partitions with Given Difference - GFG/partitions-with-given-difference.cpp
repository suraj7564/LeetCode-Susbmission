//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        long long sum = accumulate(arr.begin(), arr.end(), 0);
        int cnt = 0;
        for(auto x:arr){
            cnt += x == 0;
        }
        long long mod = 1e9 + 7;
        int t = 2*sum;
        vector<long long int> dp(7001, 0LL);
        dp[0] = 1;
        for(int i=0;i<n;i++){
            for(int j=7000;j>=arr[i];j--){
                dp[j] = (dp[j]%mod + dp[j - arr[i]]%mod)%mod; 
            }
        }
        long long ans = 0;
        for(int i=0;i<=7000;i++){
            long long a = i, b = sum - i;
            if(a - b == d){
                ans = dp[i];
                break;
            }
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends