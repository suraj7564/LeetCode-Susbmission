//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        sort(words.begin(), words.end(), [&](string &a, string &b){
            return a.length() < b.length();
        });
        map<string, int> m;
        string ans = "";
        for(auto x:words){
            m[x] = 1;
            string cur = "";
            bool flag = true;
            for(auto y:x){
                cur += y;
                if(m[cur] == 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(ans.length() < x.length()){
                    ans = x;
                }
                else if(ans.length() == x.length()){
                    ans = min(ans, x);
                }
            }
           // cout<<x<<" ";
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends