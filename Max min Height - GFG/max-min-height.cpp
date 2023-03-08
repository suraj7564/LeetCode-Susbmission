//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        bool check(int k, int w, vector<int> &a, long long int m){
            int n = a.size();
            vector<long long> b(n, 0);
            long long int cur = 0, op = 0;
            for(int i=0;i<n;i++){
                cur += b[i];
                if(cur + a[i] < m){
                    long long int curAns = m - cur - a[i];
                    cur += curAns;
                    op += curAns;
                    if(i + w < n){
                        b[i + w] -= curAns;
                    }
                }
            }
            
            return op <= k;
        }
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            // code here
            long long int ans = 0, l = 0, r = 2e9;
            while(l <= r){
                long long int m = l + (r - l)/2LL;
                if(check(k, w, a, m)){
                    ans = m;
                    l = m + 1LL;
                }
                else{
                    r = m - 1LL;
                }
            }
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
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends