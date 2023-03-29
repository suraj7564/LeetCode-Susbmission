//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        int ans = 0;
        for(int i=0;i<S.length();i++){
            int x = 0, y = 0;
            for(int j=i;j<S.length();j++){
                if(S[j] >= 'A' && S[j] <= 'Z') x++;
                else y++;
                //cout<<x<<" "<<y<<endl;
                ans += x == y;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends