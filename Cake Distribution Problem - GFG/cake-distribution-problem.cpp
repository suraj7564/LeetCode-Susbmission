//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool check(vector<int>& a, long long m, int k){
        long long n = a.size(), cur = 0, cnt = 0;
        for(int i=0;i<n;i++){
            cur += (long long)a[i];
            if(cur >= m){
                cur = 0;
                cnt++;
            }
        }
        return cnt >= (k + 1);
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    // Write your code here.
        long long l = 0, r = 1e16, ans = 0;
        while(l <= r){
            long long m = l + (r - l)/2;
            if(check(sweetness, m, K)){
                ans = m;
                l = m + 1LL;
            }
            else{
                r = m - 1LL;
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
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends