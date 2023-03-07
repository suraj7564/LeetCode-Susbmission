//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        string ans = "";
        bool flag = false;
        for(auto x:s){
            while(ans.size() > 0 && ans.back() > x && k > 0){
                ans.pop_back();
                k--;
            }
            if(ans == ""){
                if(x != '0') ans += x;
                else flag = true;
            }
            else
                ans += x;
        }
        while(ans != "" && k-- > 0) ans.pop_back();
        if(flag && ans == "") return "0";
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends