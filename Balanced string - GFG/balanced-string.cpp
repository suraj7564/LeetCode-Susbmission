//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string BalancedString(int N) {
        string alphabet = "abcdefghijklmnopqrstuvwxyz";

        string ans = "";
        int dig = N;

        while(N > 26){
            ans += alphabet;
            N -= 26;
        }

        int start = 0, end = 0;
        int sum = 0;

        while(dig > 0){
            sum += dig % 10;
            dig /= 10;
        }

        if((N & 1) == 1){
            if((sum & 1) == 1){
                start = (N - 1) / 2;
                end = (N + 1) / 2;
            }else {
                start = (N + 1) / 2;
                end = (N - 1) / 2;
            }

        }else{
                start = N / 2;
                end = N / 2;

        }
        ans += alphabet.substr(0, (start));
        ans += alphabet.substr((26 - end), end);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends