//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string s, int n) {
        // code here
        int cur = 0, l = -1, r = -1, mx = -1, st = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1') cur--;
            else cur++;
            if(mx < cur){
                l = st+1, r = i+1, mx = cur;
            }
            if(cur < 0){
                st = i+1, cur = 0;
            }
        }
        if(mx == -1) return {-1};
        
        return {l, r};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends