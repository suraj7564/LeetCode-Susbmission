// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> graycode(int n)
    {
        //code here
        vector<string> ans;
        int t=(1<<n);
        string s="";
        for(int i=1;i<=n;i++){
            s+='0';
        }
        ans.push_back(s);
        for(int i=1;i<t;i++){
            s="";
            int x=(i^(i>>1));
            while(x){
                if(x%2){
                    s+='1';
                }
                else{
                    s+='0';
                }
                x=x>>1;
            }
            while(s.length()<n){
                s+='0';
            }
            reverse(s.begin(),s.end());
            ans.push_back(s);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        cout<<"\n";
    }
}



  // } Driver Code Ends