//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findPivot(int a[], int l, int r, int n){
        while(l <= r){
            int m = (l + r)/2;
            if(m + 1 < n && a[m] > a[m + 1]) return m;
            if(m - 1 >= 0 && a[m] < a[m - 1]) return m - 1;
            
            if(a[l] <= a[m]) l = m + 1;
            else r = m - 1;
        }
        return r;
    }
    int findMin(int arr[], int n){
        //complete the function here
        int pivot = findPivot(arr, 0, n - 1, n);
        //cout<<pivot<<" ";
        return arr[(pivot + 1)%n];
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends