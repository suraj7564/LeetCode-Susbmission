//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int n, vector<int> &arr) {
        // code here
        stack<int> s1;
        vector<int> pre(n, -1);
        for(int i=0;i<n;i++){
            while(!s1.empty() && arr[s1.top()] > arr[i]){
                s1.pop();
            }
            if(!s1.empty()){
                pre[i] = s1.top();
            }
            s1.push(i);
        }
        stack<int> s2;
        long long ans = 0, mod = 1e9 + 7;
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && arr[s2.top()] >= arr[i]){
                s2.pop();
            }
            if(!s2.empty()){
                long long cur = (long long)(s2.top() - i) * (long long)(i - pre[i]);
                cur = (cur%mod * (long long)arr[i])%mod;
                ans = (ans%mod + cur%mod)%mod;
            }
            else{
                long long cur = (long long)(n - i) * (long long)(i - pre[i]);
                cur = (cur%mod * (long long)arr[i])%mod;
                ans = (ans%mod + cur%mod)%mod;
            }
            s2.push(i);
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

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends