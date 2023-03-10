//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        int l = 0, r = 0, ans = 10000000, n = str1.length();
        for(int i=0;i<n;i++){
            int k = 0;
            for(int j=i;j<n;j++){
                if(str1[j] == str2[k]){
                    k++;
                }
                if(k == str2.length()){
                    if(ans > j - i + 1){
                        ans = j - i + 1;
                        l = i, r = j;
                    }
                    break;
                }
            }
        }
        if(ans == 10000000) return "";
        
        return str1.substr(l, r - l + 1);
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends