// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int a[], int n)
    {
        vector<int> left(n,-1);
    	stack<int> s1;
    	for(int i=0;i<n;i++){
    		while(!s1.empty()&&a[s1.top()]>=a[i]){
    			s1.pop();
    		}
    		if(!s1.empty()) left[i] = s1.top();
    		s1.push(i);
    	}
    	while(!s1.empty()) s1.pop();
    	vector<int> right(n,n);
    	for(int i=n-1;i>=0;i--){
    		while(!s1.empty()&&a[s1.top()]>=a[i]){
    			s1.pop();
    		}
    		if(!s1.empty()) right[i] = s1.top();
    		s1.push(i);
    	}
    	vector<int> ans(n+1,-1e9-1);
    	for(int i=0;i<n;i++){
    		int len = right[i]-left[i]-1;
    		ans[len] = max(a[i],ans[len]);
    	}
    	vector<int> res;
    	for(int i=n-1;i>=1;i--){
    		ans[i] = max(ans[i],ans[i+1]);
    	}
    	for(int i=1;i<=n;i++)
    		res.push_back(ans[i]);
    	return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends