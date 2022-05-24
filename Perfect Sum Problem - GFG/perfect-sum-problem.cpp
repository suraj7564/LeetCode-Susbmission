// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<long long> dp(sum+1,0);
        dp[0] = 1;
        long long mod = 1e9+7;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=arr[i];j--){
                if(dp[j-arr[i]]){
                    dp[j] = (dp[j]%mod+dp[j-arr[i]]%mod)%mod; 
                }
            }
        }
        return dp[sum];
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends