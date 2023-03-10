//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int get(vector<int> &arr, int n, int k){
        vector<int> m(n + 1, 0);
        int j = 0, ans = 0, diff = 0;
        for(int i=0;i<n;i++){
            if(m[arr[i]] == 0) diff++;
            m[arr[i]]++;
            while(diff > k){
                m[arr[j]]--;
                if(m[arr[j]] == 0) diff--;
                j++;
            }
            ans += i - j + 1;
        }
        return ans;
    }
    int subarrayCount(vector<int> &arr, int n, int k) {
        // code here
        int ans = get(arr, n, k) - get(arr, n, k-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends