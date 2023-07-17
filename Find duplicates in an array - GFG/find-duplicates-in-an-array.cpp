//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> ans;
        
        unordered_map<int, int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        
        for(auto x:m){
            if(x.second > 1){
                ans.push_back(x.first);
            }
        }
        
        if(ans.size() == 0) return {-1};
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends