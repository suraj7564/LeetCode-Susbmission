//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int check(int a[], int n, int k, int m){
        int cur = 0;
        for(int i=0;i<n;i++){
            if(a[i] > m){
                cur += a[i] - m;
            }
        }
        if(cur == k) return 2;
        return cur >= k;
    }
    int find_height(int tree[], int n, int k)
    {
        // code here
        int ans = -1, l = 0, r = 1000;
        while(l <= r){
            int m = (l + r)/2;
            int res = check(tree, n, k, m);
            if(res == 2){
                return m;
            }
            if(res == 1){
                l = m + 1;
            }
            else{
                r = m - 1;
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
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}
// } Driver Code Ends