//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int a[], int n) {
        // code here
        vector<int> ans;
        sort(a, a + n);
        for(int i=1;i<n;i++){
            if(a[i] != a[i - 1]){
                if(i > 1 && a[i - 1] == a[i - 2]){
                    ans.push_back(a[i - 1]);
                }
            }
        }
        if(n > 1){
            if(a[n - 1] == a[n - 2]){
                ans.push_back(a[n - 1]);
            }
        }
        if(ans.size() == 0) return {-1};
        
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