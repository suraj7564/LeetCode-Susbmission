//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int nums[], int n){
        // Your code here
        int jump = 0, cur = -1, mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx, i+nums[i]);
            if(cur<=i){
                if(i != n-1)
                   jump++;
                cur = max(cur, mx);
            }
            if(cur<i) return -1;
            if(i != n-1 && cur<=i) return -1;
        }
        return jump;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends