//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        vector<int> dp(n+1, 0);
        vector<int> pre;
        pre.push_back(0);
        for(int i=0;i<n;i++){
            int idx = upper_bound(pre.begin(), pre.end(), intervals[i][0]) - pre.begin();
            idx--;
            dp[i+1] = max(dp[i], intervals[i][2] + dp[idx]);
            pre.push_back(intervals[i][1]);
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends