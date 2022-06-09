// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    long long cnt = 0;
	    sort(arr,arr+n);
	    for(int i=0;i<n;i++){
	        int j = i+1, k = n-1;
	        while(j<k){
	            if(arr[i]+arr[j]+arr[k]<sum){
	                cnt += (long long)(k-j);
	                j++;
	            }
	            else{
	                k--;
	            }
	        }
	    }
	    return cnt;
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
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends