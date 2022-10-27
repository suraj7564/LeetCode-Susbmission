//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    unordered_map<int, int> m;
    vector<int> ans;
    int idx = 0, N;
    void findLeaf(int pre[], int l, int r){
        if(l>r) return;
        if( l == r){
            ans.push_back(pre[idx]);
            //return;
        }
        if(idx == N) return;
        int p = idx;
        idx++;
        findLeaf(pre, l, m[pre[p]]-1);
        findLeaf(pre, m[pre[p]]+1, r);
    }
    vector<int> leafNodes(int pre[],int n) {
        // code here
        N = n;
        int in[n];
        for(int i=0;i<n;i++){
            in[i] = pre[i];
        }
        sort(in, in+n);
        for(int i=0;i<n;i++){
            m[in[i]] = i;
        }
        findLeaf(pre, 0, n-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends