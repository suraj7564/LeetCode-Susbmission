//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &r){
        // Code here
        sort(r.begin(), r.end());
        vector<int> st(n), suf(n);
        int mx = 0;
        for(int i=n-1;i>=0;i--){
            mx = max(mx, r[i][2]);
            suf[i] = mx;
            st[i] = r[i][0];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int idx = lower_bound(st.begin() + i + 1, st.end(), r[i][1]) - st.begin();
            if(idx >= n){
                ans = max(ans, r[i][2]);
            }
            else{
                ans = max(ans, r[i][2] + suf[idx]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends