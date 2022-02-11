// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }
        string ans="11";
        for(int i=3;i<=n;i++){
            string cur="";
            char ch=ans[0];
            int cnt=1;
            for(int j=1;j<ans.length();j++){
                if(ans[j-1]==ans[j]){
                    cnt++;
                }
                else{
                    cur+=to_string(cnt);
                    cur+=ch;
                    cnt=1;
                    ch=ans[j];
                }
            }
            cur+=to_string(cnt);
            cur+=ch;
            //cout<<cur<<" "<<cnt<<endl;
            ans=cur;
        }
        return ans;
    }   
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends