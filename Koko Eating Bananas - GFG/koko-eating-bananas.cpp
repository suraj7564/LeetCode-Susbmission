//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool check(vector<int>& a, int h, int m){
        int cnt = 0;
        for(int i=0;i<a.size();i++){
            cnt += (a[i] + m - 1)/m;
        }
        return cnt <= h;
    }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        long long l = 0, r = 1e9, ans = -1;
        while(l <= r){
            long long m = l + (r - l)/2;
            if(check(piles, H, m)){
                ans = m;
                r = m - 1;
            }
            else{
                l = m + 1;
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
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends