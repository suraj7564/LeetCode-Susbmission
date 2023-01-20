//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int isPossible(int val)
    {
        int zero = 0;
        while(val)
        {
            zero = zero+val/5;
            val = val/5;
        }
        return zero;
    }
    int solve(int n)
    {
        int start = 0, end = 1e6;
        int ans = 0;
        while(start<end)
        {
            int mid = start+(end-start)/2;
            int temp = isPossible(mid);
            if(temp<=n)
            {
                ans = mid;
                start = mid+1;
            }
            else
            {
                end = mid;
            }
        }
        return ans;
    }
    int countZeroes(int n){
        // Code here
        int ans1 = solve(n);
        int ans2 = solve(n-1);
        return ans1-ans2;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
    	 int n;
    	 cin>>n;
    	 Solution obj;
    	 cout << obj.countZeroes(n);
    	 cout <<endl;
	}
	return 0;
}


// } Driver Code Ends