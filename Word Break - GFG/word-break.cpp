//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_map<string, int> m;
    int check(int i, string &s, vector<int>& dp){
        if(i == s.length()){
            return 1;
        }
        
        if(dp[i] != -1) return dp[i];
        
        dp[i] = 0;
        string cur = "";
        for(int j=i;j<s.length();j++){
            cur += s[j];
            if(m[cur] == 1 && check(j+1, s, dp) == 1){
                dp[i] = 1;
            }
        }
        return dp[i];
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        for(auto x:B){
            m[x] = 1;
        }
        vector<int> dp(A.size(), -1);
        return check(0, A, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends