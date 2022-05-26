// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long mod = 1e9+7;
    void find(long long a[2][2],long long b[2][2]){
        long long c[2][2] = {{0,0},{0,0}};
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    c[i][j] = (c[i][j]%mod+(a[i][k]%mod*b[k][j]%mod)%mod)%mod; 
                }
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                a[i][j] = c[i][j]%mod;
            }
        }
    }
    int firstElement(int n) 
    {
        // code here
        long long a[2][2] = {{1,1},{1,0}};
        
        long long I[2][2] = {{1,0},{0,1}};
        
        while(n){
            if(n%2){
                find(I,a);
                n--;
            }
            find(a,a);
            n = n>>1;
        }
        
        return I[1][0];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.firstElement(n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends