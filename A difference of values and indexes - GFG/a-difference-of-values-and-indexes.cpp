//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        // Complete the function
        vector<int> sufMx(n), sufMn(n);
        int mx = -1e7, mn = 1e7;
        for(int i=n-1;i>=0;i--){
            mx = max(mx, arr[i]+i);
            mn = min(mn, arr[i]-i);
            sufMx[i] = mx;
            sufMn[i] = mn;
        }
        int ans = 0;
        for(int i=0;i<n-1;i++){
            ans = max({ans, abs(arr[i] - sufMx[i] + i), abs(arr[i] - sufMn[i] - i)});
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends