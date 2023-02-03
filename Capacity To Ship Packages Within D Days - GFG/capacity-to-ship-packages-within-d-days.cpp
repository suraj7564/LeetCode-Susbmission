//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool check(int a[], int n, int d, int m){
        int sum = 0, cnt = 1;
        for(int i=0;i<n;i++){
            if(a[i] > m) return false;
            if(sum + a[i] > m){
                cnt++;
                sum = 0;
            }
            sum += a[i];
        }
        return cnt <= d;
    }
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int l = 0, r = 1e8, ans = 0;
        while(l <= r){
            int m = (l + r)/2;
            if(check(arr, N, D, m)){
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
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends