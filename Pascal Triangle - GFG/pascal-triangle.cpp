//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        if(n == 1) return {1};
        if(n == 2) return {1, 1};
        vector<ll> pre = {1, 1};
        int mod = 1e9 + 7;
        for(int i=2;i<n;i++){
            vector<ll> cur;
            cur.push_back(1);
            for(int j=1;j<i;j++){
                cur.push_back((pre[j] + pre[j - 1])%mod);
            }
            cur.push_back(1);
            pre = cur;
        }
        return pre;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends