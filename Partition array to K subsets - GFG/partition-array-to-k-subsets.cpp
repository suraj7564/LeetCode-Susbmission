//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum = 0;
         for(int i=0;i<n;i++){
             sum += a[i];
         }
         if(sum%k) return 0;
         int t = sum/k;
         vector<int> dp(1<<n, -1);
         dp[0] = 0;
         for(int i=0;i<(1<<n);i++){
             if(dp[i] == -1) continue;
             for(int j=0;j<n;j++){
                 if(!(i&(1<<j)) && dp[i] + a[j] <= t){
                     dp[i | (1<<j)] = (dp[i] + a[j])%t;
                 }
             }
         }
         return dp[(1<<n)-1] == 0;
    }
};

//{ Driver Code Starts.
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
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends