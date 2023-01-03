//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends



class Solution
{
    public:
    //Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(int arr[], int n)
    {
        //Your code here
        int lef[n], ri[n];
        lef[0] = arr[0];
        ri[n-1] = arr[n-1];

        int ans = max(lef[0], ri[n-1]);

        for(int i=1; i<n; i++){
            lef[i] = max(arr[i], arr[i]+lef[i-1]);
            ans = max(ans, lef[i]);
        }

        for(int i=n-2; i>=0; i--){
            ri[i] = max(arr[i], arr[i]+ri[i+1]);
            ans = max(ans, ri[i]);
        }

        for(int i=1; i<n-1; i++){
            ans = max(ans, lef[i-1]+ri[i+1]);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	
	//taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking total elements
		int n;
		cin>>n;
		int a[n];
		
		//inserting elements in the array
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		
		//calling method maxSumSubarray()
		Solution obj;
		cout<<obj.maxSumSubarray(a,n)<<endl;
	}
}


// } Driver Code Ends