//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    int l = -1, r = -1, curl = -1, curr = -1, sum = 0, mx = 0;
	    for(int i=0;i<n;i++){
	        if(a[i]<0){
	            curl = -1, curr = -1;
	            sum = 0;
	        }
	        else{
	            if(curl == -1) curl = i;
	            curr = i;
	            sum += a[i];
	        }
	        if(mx < sum){
	            mx = sum, l = curl, r = curr;
	        }
	        else if(mx == sum){
	            if(r-l < curr - curl){
	                r = curr, l = curl;
	            }
	        }
	    }
	    if(l == -1) return {-1};
	    vector<int> ans;
	    for(int i=l;i<=r;i++){
	        ans.push_back(a[i]);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends