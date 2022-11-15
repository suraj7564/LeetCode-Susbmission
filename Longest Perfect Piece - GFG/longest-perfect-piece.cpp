//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
        int mn = 1e6, mx = 0, cur = 0, ans = 1;
        for(int i=0;i<N;i++){
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
            if(mx - mn <= 1){
                cur++;
            }
            else{
                mn = arr[i], mx = arr[i], cur = 1;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends