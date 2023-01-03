//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    long long maxTip(int a[], int b[], int n, int x, int y) {
        // code here
        vector<vector<long long>> ar;
        for(int i=0;i<n;i++){
            ar.push_back({a[i] - b[i], a[i], b[i]});
        }
        sort(ar.begin(), ar.end());
        vector<long long> pre(n), suf(n);
        long long sum1 = 0, sum2 = 0; 
        for(int i=0;i<n;i++){
            sum1 += ar[i][2];
            sum2 += ar[n - 1 - i][1];
            pre[i] = sum1;
            suf[n - 1 - i] = sum2;
        }
        long long ans = pre[min(y-1, n-1)];
        if(y < n) ans += suf[y];
        
        for(int i=min(y-1, n-1);i>=0 && i >= n-x;i--){
            long long cur = suf[i];
            if(i > 0) cur += pre[i-1];
            ans = max(ans, cur);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        Solution obj;
        auto ans = obj.maxTip(a, b, n, x, y);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends