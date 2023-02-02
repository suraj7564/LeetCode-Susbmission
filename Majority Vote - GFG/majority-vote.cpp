//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        sort(nums.begin(), nums.end());
        int cnt = 1;
        vector<int> ans;
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i - 1]) cnt++;
            else{
                if(cnt > n/3) ans.push_back(nums[i - 1]);
                cnt = 1;
            }
        }
        if(cnt > n/3) ans.push_back(nums[n - 1]);
        if(ans.size() > 0) return ans;
        return {-1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends