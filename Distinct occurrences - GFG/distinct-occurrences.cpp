//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int mod = 1e9 + 7, n, m;
    long long solve(int i, int j, string &s, string &t, vector<vector<long long>>& dp){
        if(j == m) return 1;
        if(i == n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        long long ans = solve(i+1, j, s, t, dp);
        
        if(s[i] == t[j]){
            ans = (ans + solve(i+1, j+1, s, t, dp))%mod;
        }
        
        return dp[i][j] = ans%mod;
    }
    int subsequenceCount(string S, string T)
    {
      //Your code here
        n = S.length(), m = T.length();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        return solve(0, 0, S, T, dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends