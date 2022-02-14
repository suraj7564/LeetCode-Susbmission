// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int checkBits(int *arr, int n, int pattern) {
       int cnt = 0;
       for (int i = 0; i < n; ++i) {
          if ((pattern & arr[i]) == pattern) {
             ++cnt;
          }
       }
       return cnt;
    }

    int maxAND (int arr[], int n)
    {
        int result = 0;
       int count;
       for (int i = 31; i >= 0; --i) {
          count = checkBits(arr, n, result | (1 << i));
          if (count >= 2) {
             result |= (1 << i);
          }
       }
       return result;
    }
};

// { Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends