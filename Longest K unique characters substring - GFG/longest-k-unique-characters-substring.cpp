// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        map<char,int> m;
        int ans = 0;
        int l = 0;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            if(m.size()>k){
                char c = s[l];
                while(c == s[l]){
                    l++;
                    m[c]--;
                }
                if(m[c]==0) m.erase(c);
            }
            if(m.size()==k) ans = max(ans,i-l+1);
        }
        if(m.size()<k) return -1;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends