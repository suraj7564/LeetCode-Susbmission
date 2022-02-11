// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int countWays(int N)
	{
	    //1 2 3 4 5 6
		int mod=1e9+7;
		long long odd=(N+1)/2;
		long long even=N/2;
        long long ans=0;
        if(even>2){
            ans=(even*(even-1)*(even-2))/6;
        }
        if(odd>1){
            ans+=even*(odd*(odd-1))/2;
        }
        ans=ans%mod;
        return (int)(ans);
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
	    cout << ob.countWays(n) << "\n";
   
    }
    return 0;
}  // } Driver Code Ends