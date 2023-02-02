//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        // sum = n * (n + 1)/2
        // sqSum = n * (n + 1) * (2n * 1)/6
        long long sum = 0, sqSum = 0;
        for(long long i=1;i<=n;i++){
            long long cur = arr[i - 1];
            sum += i - cur;
            sqSum += i * i - cur * cur;
        }
        
        long long sumb = sqSum/sum;
        
        long long a = (sum + sumb)/2;
        long long b = (sumb - sum)/2;
        if(sum > 0){
            if(a > b) swap(a, b);
        }
        else{
            if(a < b) swap(a, b);
        }
        int ans[2];
        ans[0] = a, ans[1] = b;
        int *res = ans;
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends