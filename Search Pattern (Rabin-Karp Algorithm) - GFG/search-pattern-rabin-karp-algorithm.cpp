// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string s)
        {
            //code here.
            vector<int> ans;
            int p = 31;
            int m = 1e9+7;
            int n = s.length();
            vector<long long> power(n,0);
            power[0] = 1;
            for(int i=1;i<n;i++){
                power[i] = (power[i-1]*p*1LL)%m;
            }
            vector<long long> sh(n+1,0);
            for(int i=0;i<n;i++){
                sh[i+1] = (sh[i]+(s[i]-'a'+1)*1LL*power[i])%m;
            }
            int m1 = pat.length();
            vector<long long> ph(m1+1,0);
            for(int i=0;i<m1;i++){
                ph[i+1] = (ph[i]+(pat[i]-'a'+1)*1LL*power[i])%m;
            }
            for(int i=0;i+m1-1<n;i++){
                long long cur_h = (sh[i+m1]+m-sh[i])%m;
                if(cur_h==(ph[m1]*power[i])%m){
                    ans.push_back(i+1);
                }
            }
            if(ans.size()>0) return ans;
            return {-1};
        }
     
};

// { Driver Code Starts.
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
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends