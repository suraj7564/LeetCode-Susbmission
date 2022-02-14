// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    vector<string> yShapedPattern(int n) {
        // code, here
        vector<string> ans;
        for(int i=0; i<n; i++){
	        for(int j=0; j<=n; j++){
	            if(i>n/2){
	                if(j==n/2) cout<<'*';
	                else cout<<' ';
	            }
	            else{
	                if(i==j||i+j==n) cout<<'*';
	                else cout<<' ';
	            }
	        }
	        cout<<endl; //should uncomment to get 'Y'
	    }
	    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<string> v = ob.yShapedPattern(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    }
    return 0;
}  // } Driver Code Ends