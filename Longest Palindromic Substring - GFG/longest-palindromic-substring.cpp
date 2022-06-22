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
        int l = 1;
        int n = s.length();
        int dp[n+1][n+1];
        for(int l=0;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                if(l<=1) dp[l][i] = 1;
                else{
                    if(s[i]==s[i+l-1]&&dp[l-2][i+1]==1){
                        dp[l][i] = 1;
                        if(l>ans.length()){
                            ans = s.substr(i,l);
                        }
                    }
                    else dp[l][i] = 0;
                }
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