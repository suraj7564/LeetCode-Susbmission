// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        //<vector<int>> dp(N+1,vector<int>(W+1,0));
        vector<int> dp(W+1,0);
        for(int i=1;i<=W;i++){
            for(int j=0;j<N;j++){
                if(i>=wt[j]){
                    dp[i] = max(dp[i],dp[i-wt[j]]+val[j]);
                }
            }
        }
        return dp[W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends