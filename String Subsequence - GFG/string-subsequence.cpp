//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int get(int i, int j, string &a, string & b){
        if(j == b.length()) return 1;
        if(i == a.length()) return 0;
        
        int ans = get(i + 1, j, a, b);
        if(a[i] == b[j]){
            ans += get(i + 1, j + 1, a, b);
        }
        return ans;
    }
    int countWays(string a, string b){
        // code here
        //int cnt = get(0, 0, a, b);
        
        int m = a.length();
        int n = b.length();
     
        // Create a table to store results of sub-problems
        int DP[m + 1][n + 1] = { { 0 } };
     
        // If first string is empty
        for (int i = 0; i <= n; ++i)
            DP[0][i] = 0;
     
        // If second string is empty
        for (int i = 0; i <= m; ++i)
            DP[i][0] = 1;
     
        // Fill lookup[][] in bottom up manner
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // If last characters are same, we have two
                // options -
                // 1. consider last characters of both strings
                //    in solution
                // 2. ignore last character of first string
                if (a[i - 1] == b[j - 1])
                    DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
                     
                else
                    // If last character are different, ignore
                    // last character of first string
                    DP[i][j] = DP[i - 1][j];
            }
        }
     
        return DP[m][n];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends