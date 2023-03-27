//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int count(string s){
        int n = s.length();
        vector<int> mark(129, -1);
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            dp[i] = 2 * dp[i - 1];
            if(mark[s[i - 1]] != -1){
                dp[i] = dp[i] - dp[mark[s[i - 1]]];
            }
            mark[s[i - 1]] = i - 1;
        }
        return dp[n];
    }
    string betterString(string str1, string str2) {
        // code here
        int x = count(str1), y = count(str2);
        if(x >= y) return str1;
        return str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends