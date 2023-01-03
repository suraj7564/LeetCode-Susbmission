//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        // code here
        // aebcbda
        // adbcbea
        int n = s.length();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i] == s1[j]){
                    dp[i+1][j+1] = 1 + dp[i][j];
                }
                else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return n - dp[n][n];
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends