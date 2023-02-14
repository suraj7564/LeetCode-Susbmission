//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0;i<n;i++){
	        sum += arr[i];
	    }
	    vector<int> dp(sum+1, 0);
	    dp[0] = 1;
	    for(int i=0;i<n;i++){
	        for(int j=sum;j>=arr[i];j--){
	            dp[j] |= dp[j-arr[i]];
	        }
	    }
	    int ans = 1e9;
	    for(int i=0;i<=sum;i++){
	        if(dp[i])
	            ans = min(ans, abs(sum - 2*i));
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends