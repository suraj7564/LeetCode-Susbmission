//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int n, vector<int> color, vector<int> radius) {
        stack<pair<int, int>> s1;
        for(int i=0;i<n;i++){
            if(s1.empty()){
                s1.push({color[i], radius[i]});
            }
            else{
                pair<int, int> p = {color[i], radius[i]};
                if(s1.top() == p){
                    s1.pop();
                }
                else{
                    s1.push(p);
                }
            }
        }
        return s1.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends