// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        int n=s.length();
        vector<vector<int> > dp(n+1,vector<int>(n+1,0));
        string res="";
        res+=s[0];
        int ans=0;
        int l=0,r=0;
        for(int i=0;i<=n;i++){
            dp[i][0]=dp[i][1]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(s[j-1]==s[j-i]&&dp[j-1][i-2]==1){
                    dp[j][i]=1;
                    l=j-i;
                    r=j-1;
                    if((r-l+1)>res.length())
                    res=s.substr(l,r-l+1);
                }
                else dp[j][i]=0;
            }
        }
        
        return res;
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