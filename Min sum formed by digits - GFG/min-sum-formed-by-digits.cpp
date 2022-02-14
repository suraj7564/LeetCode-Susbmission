// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        sort(arr,arr+n);
        string ans="";
        long long carry=0;
        for(int i=n-1;i>=0;i-=2){
            long long cur=arr[i]+carry;
            if(i>0){
                cur+=arr[i-1];
            }
            ans+=(char)(cur%10+'0');
            carry=cur/10;
        }
        if(carry>0){
            ans+=(char)(carry+'0');
        }
        long long res=0;
        for(int i=ans.length()-1;i>=0;i--){
            res=res*10+(ans[i]-'0');
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends