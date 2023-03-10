//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int K) {
        // code here
        long long sum = 0;
        for(int i=0;i<K;i++){
            sum += (long long)cardPoints[i];
        }
        long long ans = sum;
        for(int i=N-1;i>=N-K;i--){
            sum += cardPoints[i] - cardPoints[K - (N - i)];
            ans = max(ans, sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends