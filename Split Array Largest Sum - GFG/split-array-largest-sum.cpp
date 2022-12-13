//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(int a[], int n, long long l, int k){
        int cnt = 1, cur = 0;
        for(int i=0;i<n;i++){
            if(a[i] > l) return false;
            if(cur + a[i] > l){
                cur = a[i];
                cnt++;
            }
            else{
                cur += a[i];
            }
        }
        return cnt <= k;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        long long l = 0, r = 1e9, ans = 0;
        while(l <= r){
            long long m = l + (r - l)/2;
            if(check(arr, N, m, K)){
                ans = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
            //cout<<l<<" "<<r<<endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends