//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int> cnt(26, 0);
        for(auto x:s){
            cnt[x - 'a']++;
        }
        int ans = min({cnt['a' - 'a'], cnt['b' - 'a'], cnt['n' - 'a']});
        ans = min({ans, cnt['l' - 'a']/2, cnt['o' - 'a']/2});
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends