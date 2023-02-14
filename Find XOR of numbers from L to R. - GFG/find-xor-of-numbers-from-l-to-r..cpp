//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int get(int x){
        if(x%4 == 1) return 1;
        if(x%4 == 2) return x + 1;
        if(x%4 == 3) return 0;
        return x;
    }
    int findXOR(int l, int r) {
        // complete the function here
        // 1 2 3 4 5 6 7 8 9
        // 1 3 0 4 1 7 0 8 1
        int a = get(r);
        int b = get(l - 1);
        return a ^ b;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends