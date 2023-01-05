//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        // code here
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=0;i<=n;i++){
            dp[i][0] = dp[i][1] = 1;
        }
        for(int l=2;l<=n;l++){
            for(int i=1;i+l-1<=n;i++){
                dp[i][l] = 0;
                if(s[i - 1] == s[i + l - 2] && dp[i+1][l-2] == 1){
                    dp[i][l] = 1;
                }
            }
        }
        set<string> s1;
        for(int i=0;i<n;i++){
            string cur = "";
            for(int j=i;j<n;j++){
                cur += s[j];
                if(dp[i + 1][j - i + 1] == 1){
                    s1.insert(cur);
                }
            }
        }
        return s1.size();
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends