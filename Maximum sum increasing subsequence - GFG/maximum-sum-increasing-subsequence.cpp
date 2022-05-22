// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int ans = 0;
    	vector<int> cur(n,0);
    	for(int i=0;i<n;i++){
    	    cur[i] = arr[i];
    		for(int j=0;j<i;j++){
    			if(arr[i]>arr[j]&&cur[i]<cur[j]+arr[i]){
    				cur[i] = cur[j]+arr[i];
    			}
    		}
    	}
    	
    	for(int i=0;i<n;i++){
    		ans = max(cur[i],ans);
    	}
    	return ans;
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

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends