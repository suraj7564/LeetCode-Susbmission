// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        string ans = "";
        ans += s[0];
        int l = 0,r = 0;
        int n = s.length();
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        for(int i=0;i<=n;i++){
            dp[i][0] = dp[i][1] = true;
        }
        for(int i=2;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(s[j-1]==s[j-i]&&dp[j-1][i-2]){
                    dp[j][i] = true;
                    if(i>ans.length())
                    ans = s.substr(j-i,i);
                }
                else dp[j][i] = false;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends