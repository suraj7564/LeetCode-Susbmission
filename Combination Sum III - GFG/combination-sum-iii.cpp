//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int i, int k, int n, vector<int>& cur, vector<vector<int>>& ans){
        if(n < 0) return;
        if(n == 0){
            if(k == 0)
                ans.push_back(cur);
            return;
        }
        for(int j=i;j<=9;j++){
            cur.push_back(j);
            solve(j + 1, k - 1, n - j, cur, ans);
            cur.pop_back();
        }
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