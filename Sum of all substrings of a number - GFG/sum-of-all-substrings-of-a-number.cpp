// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        long long ans = 0;
        long long mod = 1e9+7;
        long long res = 0;
        int n = s.length();
        for(int i=1;i<=n;i++){
            ans = ((ans*10LL)%mod+(i*(s[i-1]-'0'))%mod)%mod;
            res = (ans%mod+res%mod)%mod;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}
  // } Driver Code Ends