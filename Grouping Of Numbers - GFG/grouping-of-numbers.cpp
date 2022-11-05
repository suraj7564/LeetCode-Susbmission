//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int a[], int N, int k) {
        // code here
        map<int, int> m;
        int ans = 0;
        for(int i=0;i<N;i++){
            m[a[i]%k]++;
        }
        if(m[0]>0) ans++;
        if(m[k/2]>0 && k%2 == 0) ans++;
        int total = N;
        for(int i=1;i<k/2;i++){
            ans += max(m[i], m[k-i]);
        }
        if(k%2) ans += max(m[k/2], m[k - k/2]);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends