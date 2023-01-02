//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int n, mod = 1e9 + 7;
	    long long solve(int i, string& s, vector<long long>& dp){
	        if(i >= n) return 1;
	        
	        if(dp[i] != -1) return dp[i];
	        int ans = 0;
	        
	        if(s[i] != '0'){
	            ans = (ans%mod + solve(i+1, s, dp)%mod)%mod;
	        }
	        if(s[i] != '0' && i+1 < n && stoi(s.substr(i, 2)) <= 26){
	            ans = (ans%mod + solve(i+2, s, dp)%mod)%mod;
	        }
	        
	        return dp[i] = ans%mod;
	    }
		int CountWays(string str){
		    // Code here
		    n = str.length();
		    vector<long long> dp(n, -1);
		    long long ans = solve(0, str, dp);
		    return (int)ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends