//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int a)
	{
	    // Code here.
	    long long l = 0, r = a, ans = 0;
	    while(l<=r){
	        long long m = l + (r - l)/2;
	        long long cur = m, p = m;
	        for(int i=1;i<n;i++){
	            cur = cur * p;
	            if(cur > a){
	                break;
	            }
	        }
	        if(cur > a){
	            r = m - 1;
	        }
	        else{
	            ans = m;
	            l = m + 1;
	        }
	    }
	    long long res = 1;
	    for(int i=0;i<n;i++){
	        res *= ans;
	    }
	    if(res != a) return -1;
	    return ans;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends