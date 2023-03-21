//{ Driver Code Starts
// CPP Program to count number of ways to split 
// array into two groups such that each group 
// has equal XOR value 
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int countgroup(int a[], int n)
	{
	    int cur = 0;
	    for(int i=0;i<n;i++){
	        cur ^= a[i];
	    }
	    if(cur != 0) return 0;
	    long long x = 2, p = n - 1, ans = 1, mod = 1e9 + 7;
	    while(p){
	        if(p & 1){
	            ans = (ans * x)%mod;
	        }
	        x = (x * x)%mod;
	        p >>= 1;
	    }
	    return (ans - 1 + mod)%mod;
	}

};

//{ Driver Code Starts.

// Driver Program
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n ;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    cin>>a[i];
    Solution ob;
    cout << ob.countgroup(a, n) << endl;
  }
  return 0;
} 
// } Driver Code Ends