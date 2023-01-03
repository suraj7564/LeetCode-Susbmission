//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int a, b;
	int solve(int i, int j, int k, int A[], int B[], vector<vector<int>>& dp){
	    if(i == a || j == b) return 0;
	    
	    if(dp[i][j] != -1) return dp[i][j];
	    
	    int ans = 0;
	    if(k > 0){
	        ans = max(solve(i+1, j, k-1, A, B, dp), A[i]*B[j] + solve(i+1, j+1, k, A, B, dp));
	    }
	    else{
	        ans = A[i]*B[j] + solve(i+1, j+1, k, A, B, dp);
	    }
	    return dp[i][j] = ans;
	}
	int maxDotProduct(int n, int m, int A[], int B[]) 
	{ 
		// Your code goes here 
		a = n, b = m;
		int k = n - m;
		vector<vector<int>> dp(n, vector<int>(n, -1));
		return solve(0, 0, k, A, B, dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends