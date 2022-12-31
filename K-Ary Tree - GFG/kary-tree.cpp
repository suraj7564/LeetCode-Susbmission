//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long karyTree(int k, int m) {
        // code here
        long long a = k, res = 1, mod = 1e9 + 7, b = m;
        while(b){
            if(b & 1){
                res = (res * a)%mod;
            }
            a = (a * a)%mod;
            b = b >> 1;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}
// } Driver Code Ends