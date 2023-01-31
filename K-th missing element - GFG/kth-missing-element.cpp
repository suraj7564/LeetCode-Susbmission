//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    int l = a[0], r = a[n - 1], ans = -1;
    while(l <= r){
        int m = (l + r)/2;
        int idx = lower_bound(a, a+n, m) - a;
        int total = m - a[0] + 1;
        if(a[idx] != m) idx--;
        // 5
        //4 _ 6 _ _ _ 10 _ _ _ _ 15 _ _ _ _ 20
        //1 3 4 5 7 k = 2
        // l = 1, r = 7 
        // m = 4, 4 idx 2, total = 4, present = 3, missing = 1
        // l = 5, r = 7
        // m = 6, 7 idx 4, total = 7, pr = 5, missing = 2 ans = 6
        int present = idx + 1, missing = total - present;
        
        if(missing >= k){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return ans;
}