//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int fun(int i,int j,vector<int> &a,vector<vector<int>> &dp){
            if(i>j) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            int maxi=INT_MIN;    
            for(int ind=i;ind<=j;ind++){
                int cost = a[i-1]*a[ind]*a[j+1] + fun(i,ind-1,a,dp) + fun(ind+1,j,a,dp);
                maxi = max(maxi,cost);
            }
            return dp[i][j]=maxi;
        }
        int maxCoins(int n, vector <int> &a)
        {
            // write your code here
            a.insert(a.begin(),1);
            a.push_back(1);
            vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
            return fun(1,n,a,dp);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends