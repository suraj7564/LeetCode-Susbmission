//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string, int> mp;
    void solve(int i, vector<string>& cur, string &s, vector<string>& ans){
        if(i == s.length()){
            string res = "";
            for(int j=0;j<cur.size();j++){
                res += cur[j];
                if(j != cur.size() - 1)
                    res += " ";
            }
            ans.push_back(res);
            return;
        }
        string p = "";
        for(int j=i;j<s.length();j++){
            p += s[j];
            if(mp[p] == 1){
                cur.push_back(p);
                solve(j+1, cur, s, ans);
                cur.pop_back();
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        for(auto x:dict){
            mp[x] = 1;
        }
        vector<string> ans, cur;
        
        solve(0, cur, s, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends