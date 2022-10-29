//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> res;
        string cur = "";
        for(int i=0;i<s.length();i++){
            cur += s[i];
            set<string> temp;
            for(int j=0;j<n;j++){
                if(contact[j].substr(0, i+1) == cur){
                    temp.insert(contact[j]);
                }
            }
            if(temp.size() == 0) temp.insert("0");
            vector<string> ans(temp.begin(), temp.end());
            res.push_back(ans);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends