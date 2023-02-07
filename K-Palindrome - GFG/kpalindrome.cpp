//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


bool is_k_palin(string s,int k);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;
		
		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function*/
bool is_k_palin(string a,int k)
{
//Your code here
    string b = a;
    reverse(b.begin(), b.end());
    int n = a.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i] == b[j]){
                dp[i + 1][j + 1] = 1 + dp[i][j];
            }
            else{
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return (n - dp[n][n]) <= k;
}