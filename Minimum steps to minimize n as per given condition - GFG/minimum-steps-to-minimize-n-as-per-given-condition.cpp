// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minSteps(int n) 
	{ 
	    // Your code goes here
	    vector<int> dp(n+1,0);
	    for(int i=2;i<=n;i++){
	        int x = dp[i-1];
	        if(i%2==0) x = min(x,dp[i/2]);
	        if(i%3==0) x = min(x,dp[i/3]);
	        dp[i] = 1+x;
	    }
	    return dp[n];
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends