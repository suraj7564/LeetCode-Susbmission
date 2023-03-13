//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &r) {
        // code here
        vector<int> pre(N, 1);
        for(int i=1;i<N;i++){
            if(r[i] > r[i - 1]){
                pre[i] = pre[i - 1] + 1;
            }
        }
        vector<int> suf(N, 1);
        for(int i=N-2;i>=0;i--){
            if(r[i] > r[i + 1]){
                suf[i] = suf[i + 1] + 1;
            }
        }
        int ans = 0;
        for(int i=0;i<N;i++){
            ans += max(pre[i], suf[i]);
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
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends