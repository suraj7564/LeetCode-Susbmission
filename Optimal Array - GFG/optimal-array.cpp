//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        vector<long long> pre(n);
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += a[i];
            pre[i] = sum;
        }
        vector<int> ans(n);
        for(long long i=0;i<n;i++){
            int idx = i/2;
            int cur = (idx + 1LL) * a[idx] - pre[idx];
            cur += (pre[i] - pre[idx]) - (i - idx) * a[idx];
            ans[i] = cur;
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends