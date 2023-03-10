//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int K) {
        // code here
        int ans = 0;
        for(int j=0;j<26;j++){
            char ch = (char)(j + 'A');
            int cur = 0, k = 0;
            for(int i=0;i<s.length();i++){
                cur += s[i] != ch;
                while(cur > K){
                    cur -= s[k] != ch;
                    k++;
                }
                ans = max(ans, i - k + 1);
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
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends