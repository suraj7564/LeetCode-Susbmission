//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution
{
  public:
    // function to count the total  
    // number of ways to sum up to 'N'
    int mod = 1e9 + 7;
    int solve(int m, int N, int arr[], vector<int>& dp){
        if(N == 0) return 1;
        if(N < 0) return 0;
        if(dp[N] != -1) return dp[N];
        
        dp[N] = 0;
        for(int i=0;i<m;i++){
            dp[N] = (dp[N] % mod + solve(m, N - arr[i], arr, dp) % mod) % mod;
        }
        return dp[N] % mod;
    }
    int countWays(int arr[], int m, int N) 
    { 
        vector<int> dp(N + 1, -1);
        return solve(m, N, arr, dp);
    } 
    
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int m,n ;
	        cin>>m>>n;
	        int arr[m];
	        for(int i = 0;i<m;i++)
	            cin>>arr[i];
	        Solution ob;     
	        cout<<ob.countWays(arr,m,n)<<endl;
	    }
}
// } Driver Code Ends