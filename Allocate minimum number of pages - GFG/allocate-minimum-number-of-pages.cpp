//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool check(int a[], int n, int k, int m){
        long long cnt = 1, sum = 0;
        for(int i=0;i<n;i++){
            if(a[i] > m) return false;
            if(sum + a[i] > m){
                sum = 0, cnt++;
            }
            sum += a[i];
        }
        return cnt <= k;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N < M) return -1;
        long long l = 0, r = 1e12, ans = -1;
        while(l <= r){
            long long m = l + (r - l)/2LL;
            if(check(A, N, M, m)){
                ans = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends