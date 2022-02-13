// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    void countSort(int arr[],int n,int ex){
        vector<int> count(n,0),ans(n,0);
        for(int i=0;i<n;i++){
            count[(arr[i]/ex)%n]++;
        }
        for(int i=1;i<n;i++){
            count[i]+=count[i-1];
        }
        for(int i=n-1;i>=0;i--){
            ans[count[(arr[i]/ex)%n]-1]=arr[i];
            count[(arr[i]/ex)%n]--;
        }
        for(int i=0;i<n;i++){
            arr[i]=ans[i];
        }
    }
    void sort(int arr[], int n)
    {
        countSort(arr,n,1);
        countSort(arr,n,n);
    }
};

// { Driver Code Starts.
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


// Driver program to test above functions
int main()
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		Solution ob;
		ob.sort (arr, n);
		print (arr, n);
		cout << endl;
	}
}



  // } Driver Code Ends