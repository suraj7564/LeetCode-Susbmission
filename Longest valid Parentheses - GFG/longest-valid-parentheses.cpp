// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
        // code here
        int open=0,close=0;
        int ans1=0,ans2=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') open++;
            else close++;
            if(close>open)
            {
                open=0;
                close=0;
            }
            else if(open==close)
                ans1=max(ans1,2*close);
        }
        open=0,close=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='(') open++;
            else close++;
            if(open>close)
            {
                open=0;
                close=0;
            }
            else if(open==close)
                ans2=max(ans2,2*close);
        }
       // cout<<ans1<<" "<<ans2<<endl;
        return max(ans1,ans2);
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
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends