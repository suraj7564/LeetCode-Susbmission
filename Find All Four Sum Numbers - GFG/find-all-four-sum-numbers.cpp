//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int t) {
        // Your code goes here
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(i > 0 && arr[i] == arr[i - 1]) continue;
            for(int j=i+1;j<n;j++){
                if(j > i + 1 && arr[j] == arr[j - 1]) continue;
                int a = j + 1, b = n - 1;
                while(a < b){
                    if(a > j + 1 && arr[a] == arr[a - 1]){
                        a++;
                        continue;
                    }
                    int cur = arr[i] + arr[j] + arr[a] + arr[b];
                    if(cur == t){
                        ans.push_back({arr[i], arr[j], arr[a], arr[b]});
                        a++, b--;
                    }
                    else if(cur > t){
                        b--;
                    }
                    else{
                        a++;
                    }
                }
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
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends