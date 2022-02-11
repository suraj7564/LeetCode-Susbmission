// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    long long numberOfWays(long long N){
        long long n=N+2;
        long long ans=(n*(n-1))/2;
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
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0; 
}   // } Driver Code Ends