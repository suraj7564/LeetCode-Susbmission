//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countNumberswith4(int N) {
        // code here
        int cnt = 0;
        for(int i=4;i<=N;i++){
            for(auto x:to_string(i)){
                if(x == '4'){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countNumberswith4(N) << endl;
    }
    return 0;
}
// } Driver Code Ends