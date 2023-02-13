//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        // 1 0 0 0 1 1 0 
        long long n = num;
        i--;
        cout<<((n >> i)&1LL)<<" "<<(n | (1LL<<i))<<" "<<(n & ~(1LL<<i));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends