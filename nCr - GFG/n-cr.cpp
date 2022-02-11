// { Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long mod=1e9+7;
    long long power(long long a,long long b){
        long long res=1LL;
        while(b){
            if(b&1){
                res=(res*a)%mod;
                b--;
            }
            a=(a*a)%mod;
            b=b>>1;
        }
        return res;
    }
    long int ncr(int n, int k){
        if(n<k) return 0;
        long long ans=1;
        if(k>n-k){
            k=n-k;
        }
        for(long long i=1;i<=k;i++){
            ans=(ans*(n-i+1))%mod;
            ans=(ans*power(i,mod-2))%mod;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n, r;
        cin >> n >> r;
        Solution ob;
        cout << ob.ncr(n, r) << endl;
    
    }
    return 0; 
} 
  // } Driver Code Ends