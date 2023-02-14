//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& h, int n, int k) {
        // Code here
        vector<int> dp(n, 1e7);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0 && j>=i-k;j--){
                dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
            }
        }
        return dp[n - 1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends