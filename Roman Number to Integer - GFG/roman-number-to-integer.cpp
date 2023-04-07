//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        int ans = 0, n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == 'I'){
                ans++;
            }
            else if(s[i] == 'V'){
                ans += 5;
                if(i > 0 && s[i - 1] == 'I'){
                    ans -= 2;
                }
            }
            else if(s[i] == 'X'){
                ans += 10;
                if(i > 0 && s[i - 1] == 'I'){
                    ans -= 2;
                }
            }
            else if(s[i] == 'L'){
                ans += 50;
                if(i > 0 && s[i - 1] == 'X'){
                    ans -= 20;
                }
            }
            else if(s[i] == 'C'){
                ans += 100;
                if(i > 0 && s[i - 1] == 'X'){
                    ans -= 20;
                }
            }
            else if(s[i] == 'D'){
                ans += 500;
                if(i > 0 && s[i - 1] == 'C'){
                    ans -= 200;
                }
            }
            else{
                ans += 1000;
                if(i > 0 && s[i - 1] == 'C'){
                    ans -= 200;
                }
            }
        }
        return ans;
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
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends