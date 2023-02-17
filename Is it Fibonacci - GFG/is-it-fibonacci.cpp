//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        vector<long long> dp(N, 0);
        long long sum = 0;
        for(int i=0;i<N;i++){
            if(i < K){
                dp[i] = GeekNum[i];
            }
            else{
                dp[i] = sum;
                sum -= dp[i - K];
            }
            sum += dp[i];
        }
        return dp[N - 1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends