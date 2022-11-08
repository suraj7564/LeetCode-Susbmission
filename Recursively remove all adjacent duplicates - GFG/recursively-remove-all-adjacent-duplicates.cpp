//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        // code here
        int n = s.length();
        int cnt = 1;
        string ans = "";
        for(int i=1;i<s.length();i++){
            if(s[i] == s[i-1]){
                cnt++;
            }
            else{
                if(cnt == 1){
                    ans += s[i-1];
                }
                cnt = 1;
            }
        }
        if(cnt == 1) ans += s[n-1];
        if(ans.size() == s.size()) return ans;
        return rremove(ans);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends