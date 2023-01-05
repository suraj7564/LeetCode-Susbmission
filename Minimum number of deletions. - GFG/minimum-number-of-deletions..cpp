//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string s, int n) { 
    //complete the function here 
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    string s1 = s;
    reverse(s1.begin(), s1.end());
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i] == s1[j]){
                dp[i + 1][j + 1] = 1 + dp[i][j];
            }
            else{
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    return n - dp[n][n];
} 