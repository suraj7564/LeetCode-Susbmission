//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	vector<int> find(int arr[], int n , int x )
    {
        // code here
        int l = 0, r = n - 1;
        while(l < r){
            int m = (l + r)/2;
            if(arr[m] >= x){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        if(arr[l] != x) return {-1, -1};
        vector<int> ans;
        ans.push_back(l);
        l = 0, r = n - 1;
        while(l < r){
            int m = (l + r)/2;
            if(arr[m] > x){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        if(arr[l] == x) ans.push_back(l);
        else ans.push_back(l-1);
        return ans;
    }
	int count(int arr[], int n, int x) {
	    // code here
	    vector<int> a = find(arr, n, x);
	    if(a[0] == -1) return 0;
	    return a[1] - a[0] + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends