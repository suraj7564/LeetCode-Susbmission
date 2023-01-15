//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        sort(A, A + n);
        sort(B, B + m);
        long long sum1 = 0, sum2 = 0;
        for(int i=0;i<n;i++){
            sum1 += (long long)A[i];
        }
        for(int i=0;i<m;i++){
            sum2 += (long long)B[i];
        }
        int i = 0, j = 0;
        while(i < n && j < m){
            long long a = sum1 + (long long)B[j] - (long long)A[i];
            long long b = sum2 - (long long)B[j] + (long long)A[i];
            if(a == b) return 1;
            if(a > b){
                i++;
            }
            else{
                j++;
            }
        }
        return -1;
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends