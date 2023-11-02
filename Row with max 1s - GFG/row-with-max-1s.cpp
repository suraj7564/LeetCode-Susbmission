//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > a, int n, int m) {
	    // code here
	    int ans = 0, row = -1;
	    for(int i=0;i<n;i++){
	        int l = 0, r = m - 1, cnt = -1;
		    while(l <= r){
		        int mid = (l + r)/2;
		        if(a[i][mid] == 0){
		            cnt = mid;
		            l = mid + 1;
		        }
		        else{
		            r = mid - 1;
		        }
		    }
		    if(ans < m - cnt - 1){
		        ans = m - cnt - 1;
		        row = i;
		    }
	    }
	    return row;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends