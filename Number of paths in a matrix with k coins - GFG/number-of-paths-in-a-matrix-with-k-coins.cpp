//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    
    long long numberOfPath(int n, int K, vector<vector<int>> arr){
        
        // Code Here
        long long dp[n][n][K + 1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<=K;k++){
                    dp[i][j][k] = 0;
                    if(i == 0 && j == 0){
                        if(arr[i][j] == k){
                            dp[i][j][k] = 1;
                        }
                    }
                    if(i > 0){
                        if(arr[i][j] <= k){
                            dp[i][j][k] += dp[i - 1][j][k - arr[i][j]];
                        }
                    }
                    if(j > 0){
                        if(arr[i][j] <= k){
                            dp[i][j][k] += dp[i][j - 1][k - arr[i][j]];
                        }
                    }
                }
            }
        }
    
        return dp[n - 1][n - 1][K];
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends