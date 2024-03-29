//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long Maximize(int a[],int n)
    {
        // Complete the function
        int mod = 1e9 + 7;
        sort(a, a+n);
        long long sum = 0;
        for(long long i=0;i<n;i++){
            sum += (long long)a[i] * i;
        }
        return sum%mod;
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends