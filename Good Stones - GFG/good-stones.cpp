//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<int> dp;
    int numOfWays(int curr,vector<int> &arr){
        if(curr<0 or curr>=arr.size()) return 1;
        else if(dp[curr]>=0) return dp[curr];
        
        dp[curr]=0;
        dp[curr]+=numOfWays(curr+arr[curr],arr);
        return dp[curr];
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        dp = vector<int> (n,-1);
        
        for(int i=0;i<n;i++)
            numOfWays(i,arr);
        int ans = 0;
        for(int i=0;i<n;i++)
            if(dp[i]>0)
                ans+=dp[i];
        return ans;
    }    
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends