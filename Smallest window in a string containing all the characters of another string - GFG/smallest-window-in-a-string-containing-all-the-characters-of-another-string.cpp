//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int j = 0;
        unordered_map<char, int> m, m1;
        for(auto x:p){
            m[x]++;
            m1[x] = 0;
        }
        int ans = 1000000, l = 0, r = 0, g = 0;
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
            while(m1[s[j]] > m[s[j]]){
                m1[s[j]]--;
                j++;
            }
            bool b = true;
            if(g == 0){
                for(auto x:m){
                    if(x.second > m1[x.first]){
                        b = false;
                        break;
                    }
                }
            }
            if(b){
                g = 1;
                if(ans > i - j + 1){
                    ans = i - j + 1;
                    l = j, r = i;
                    //cout<<l<<" "<<r<<endl;
                }
            }
        }
        if(ans == 1000000) return "-1";
        return s.substr(l, r - l + 1);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends