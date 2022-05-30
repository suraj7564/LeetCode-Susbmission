// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0] = 1;                 // If 0 sum is required number of ways is 1.
	
	// Your code here
	long long arr[] = {3,5,10};
	for(int i=0;i<3;i++){
	    for(int j=arr[i];j<=n;j++){
	        table[j] += table[j-arr[i]];
	    }
	}
	
	
	return table[n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends