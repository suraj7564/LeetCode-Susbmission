// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int find(vector<vector<int>>& v,int n,int m,int i,int j,vector<vector<int>>& dp){
        if(i<0||i>=n||j<0||j>=m) return 0;
        if(j==m-1) return v[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = v[i][j]+max({find(v,n,m,i-1,j+1,dp),find(v,n,m,i,j+1,dp),find(v,n,m,i+1,j+1,dp)});
        return dp[i][j];
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int mx = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            int cur = find(M,n,m,i,0,dp);
            mx = max(mx,cur);
        }
        return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends