//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubsetXOR(int arr[], int n)
    {
        //Your code here
        int ans = 0;
        while(1){
            int mx = 0;
            for(int i=0;i<n;i++){
                mx = max(mx, arr[i]);
            }
            if(mx == 0) return ans;
            ans = max(ans, ans^mx);
            for(int i=0;i<n;i++){
                arr[i] = min(arr[i], arr[i]^mx);
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubsetXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}
// } Driver Code Ends