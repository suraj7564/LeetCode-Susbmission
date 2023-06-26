//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        if(n < r) return 0;
        // code here
        vector<vector<int>> ncr(n + 1, vector<int>(n + 1, 0));
        ncr[0][0] = 1;
        int mod = 1e9 + 7;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(j == 0 || i == j){
                    ncr[i][j] = 1;
                }
                else{
                    ncr[i][j] = (ncr[i - 1][j]%mod + ncr[i - 1][j - 1]%mod)%mod;
                }
            }
        }
        return ncr[n][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends