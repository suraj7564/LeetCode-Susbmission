//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool check(vector<int>& a, int k, int m){
        int cnt = 0;
        for(auto x:a){
            cnt += (x + m - 1)/m;
        }
        return cnt <= k;
    }
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        long long l = 1, r = 1e9, ans = -1;
        while(l <= r){
            long long m = l + (r - l)/2;
            if(check(nums, K, m)){
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
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends