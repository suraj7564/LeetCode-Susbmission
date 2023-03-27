//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int i, int k, int n, vector<int> cur, vector<vector<int>>& ans){
        if(k == 0 && n == 0){
            ans.push_back(cur);
            return;
        }
        if(k <= 0 || n <= 0 || i > 9) return;
        solve(i + 1, k, n, cur, ans);
        cur.push_back(i);
        solve(i + 1, k - 1, n - i, cur, ans);
    }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<vector<int>> ans;
        vector<int> cur;
        solve(1, K, N, cur, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends