// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        string ans="",cur="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='.'){
                if(cur=="") cur+='0';
                ans+=cur;
                ans+='.';
                cur="";
            }
            else if(cur==""){
                if(s[i]!='0')
                    cur+=s[i];
            }
            else{
                cur+=s[i];
            }
        }
        if(cur=="") cur="0";
        ans+=cur;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends