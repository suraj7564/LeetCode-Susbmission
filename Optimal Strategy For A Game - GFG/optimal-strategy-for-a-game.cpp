// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.


class Solution{
    public:
    long long find(int i,int j,vector<long long>& a,vector<vector<long long>>& dp){
      if(i>j||j<0||i>=a.size()) return 0;
     
      if(dp[i][j] != -1) return dp[i][j];
     
      if(i==j) return dp[i][j] = a[i];
      if(i+1==j) return dp[i][j] = max(a[i],a[j]);
     
      return dp[i][j] = max(a[i] + min(find(i+1, j-1, a, dp),find(i+2, j, a, dp)), a[j] + min(find(i+1, j-1, a, dp),find(i, j-2, a, dp)));
    }
    long long maximumAmount(int arr[], int n){
        vector<long long> a;
        for(int i=0;i<n;i++){
            a.push_back((long long)(arr[i]));
        }
        vector<vector<long long>> dp(n,vector<long long>(n,-1));
        long long player1 = find(0, n-1, a, dp);
        
        
        return player1;
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends