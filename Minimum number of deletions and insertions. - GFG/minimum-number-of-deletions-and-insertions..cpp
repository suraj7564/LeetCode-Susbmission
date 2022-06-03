// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	int find(string str1,string str2,int i,int j,int n,int m,vector<vector<int>>& dp){
	    if(i==n||j==m) return 0;
	    
	    if(dp[i][j]!=-1) return dp[i][j];
	    
	    
	    if(str1[i]==str2[j]){
	        dp[i][j] = 1 + find(str1,str2,i+1,j+1,n,m,dp);
	    }
	    else{
	        dp[i][j] = max(find(str1,str2,i,j+1,n,m,dp),find(str1,str2,i+1,j,n,m,dp));
	    }
	    return dp[i][j];
	}	

	public:
	int minOperations(string str1, string str2) 
	{ 
	    
	    int n = str1.length();
	    int m = str2.length();
	    vector<vector<int>> dp(n,vector<int>(m,-1));
	    int lcs = find(str1,str2,0,0,n,m,dp);
	    int del = m-lcs;
	    int ist = n-lcs;
	    return del+ist;
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends