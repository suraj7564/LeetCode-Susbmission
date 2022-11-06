//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        map<int, int> vals;
        for(int i=0;i<coins.size();i++){
            vals[coins[i]] = i;
        }
        vector<int> dp(N+1, N+1);
        dp[0] = 0;
        vector<vector<int>> res(N+1, vector<int>(15, 0));
        for(int i=1;i<=N;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j] <= i){
                    if(dp[i] > dp[i-coins[j]]+1){
                        dp[i] = 1 + dp[i-coins[j]];
                        res[i] = res[i - coins[j]];
                        res[i][vals[coins[j]]]++;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<res[N].size();i++){
            for(int j=0;j<res[N][i];j++){
                ans.push_back(coins[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends