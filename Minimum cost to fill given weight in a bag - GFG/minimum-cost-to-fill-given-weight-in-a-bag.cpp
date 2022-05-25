// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<long long> dp(W+1,INT_MAX);
        
        dp[0] = 0;
        for(int i=1;i<=N;i++){
            if(cost[i-1]==-1) continue;
            for(int j=i;j<=W;j++){
                
                dp[j] = min(dp[j],dp[j-i]+(long long)cost[i-1]);
            }
        }
        if(dp[W]==INT_MAX) return -1;
        return dp[W];
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends