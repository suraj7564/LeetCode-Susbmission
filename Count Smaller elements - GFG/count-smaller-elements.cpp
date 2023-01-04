//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    unordered_map<int, int> m;
    void add(int num){
        for(int i=num;i<=1e8;i = (i | (i+1))){
            m[i] += 1;
        }
    }
    int sum(int r){
        int ans = 0;
        for(;r>=0;r = (r&(r+1)) - 1){
            ans += m[r];
        }
        return ans;
    }
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	    vector<int> ans(n, 0);
	    for(int i=n-1;i>=0;i--){
	        ans[i] = sum(arr[i] - 1);
	        add(arr[i]);
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
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends