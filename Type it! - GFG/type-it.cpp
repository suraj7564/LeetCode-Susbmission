//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int cnt = 0, c = 1;
        while(s != ""){
            if(s.length() % 2 == 0){
                int l = s.length()/2;
                if(s.substr(0, l) == s.substr(l) && c > 0){
                    s = s.substr(0, l);
                    c--;
                }
                else{
                    s.pop_back();
                }
            }
            else{
                s.pop_back();
            }
            cnt++;
           // cout<<s<<endl;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends