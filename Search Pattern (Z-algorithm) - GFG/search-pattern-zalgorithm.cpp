//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> res;
            int n = txt.length();
            int m = pat.length();
            string s = pat + "#" + txt;
            int sz = s.length();
            vector<int> z(sz, 0);
            for(int i=0;i<sz;i++){
                if(i<=m) continue;
                int l = 0, r = 0;
                while(l<m&&(i+r)<sz&&pat[l]==s[i+r]){
                    l++,r++;
                }
                z[i] = l;
            }
            for(int i=0;i<sz;i++){
                if(z[i]==m){
                    res.push_back(i-m);
                }
            }
            return res;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends