//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long ans = -1e9;
	    long long mx = 1, mn = 1;
	    for(int i=0;i<n;i++){
	        long long a = mn*arr[i], b = mx*arr[i];
	        mn = min(a, b);
	        mx = max(a, b);
	        
	        ans = max(mx,ans);
	        
	        mx = max(1LL, mx);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends