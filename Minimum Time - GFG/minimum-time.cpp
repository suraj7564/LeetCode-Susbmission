// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minTimeForWritingChars(int N, int I, int D, int C)
    { 
	    // Your code goes here
	    vector<int> dp(2*N+2,1e9);
	    dp[0] = 0;
	    for(int i=1;i<=N+1;i++){
	        if(i%2==0){
	            dp[i] = min({dp[i],dp[i/2]+C,dp[i-1]+I});
	        }
	        else{
	            dp[i] = min({dp[i-1]+I,dp[(i+1)/2]+D+C,dp[i]});
	        }
	    }
	    
	    return dp[N];
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, i, d, c;
        cin >> n >> i >> d >> c;

	    Solution ob;
	    cout << ob.minTimeForWritingChars(n, i, d, c) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends