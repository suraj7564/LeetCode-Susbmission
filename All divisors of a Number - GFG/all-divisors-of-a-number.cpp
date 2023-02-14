//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        for(int i=1;i*i<=n;i++){
            if(n%i == 0){
                cout<<i<<" ";
            }
        }
        int x = sqrt(n);
        for(int i=x;i>=1;i--){
            if(n%i == 0 && i != n/i){
                cout<<n/i<<" ";
            }
        }
       /// cout<<endl;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends