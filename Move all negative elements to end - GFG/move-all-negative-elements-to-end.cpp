//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        int temp[n];
 
        // Traversal array and store +ve element in
        // temp array
        int j = 0; // index of temp
        for (int i = 0; i < n ; i++)
            if (arr[i] >= 0 )
                temp[j++] = arr[i];
     
        // If array contains all positive or all negative.
        if (j == n || j == 0)
            return;
     
        // Store -ve element in temp array
        for (int i = 0 ; i < n ; i++)
            if (arr[i] < 0)
                temp[j++] = arr[i];
     
        // Copy contents of temp[] to arr[]
        for(int i=0;i<n;i++){
            arr[i] = temp[i];
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends