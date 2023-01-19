//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int commDiv(long long int a,long long int b) {
        // code here
        long long int g = __gcd(a, b);
        long long int cnt = 0;
        for(long long int i = 1; i*i<=g;i++){
            if(g%i == 0){
                cnt++;
                if(i != g/i){
                    cnt++;
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
        long long int a, b;
        cin >> a >> b;
        Solution ob;
        cout<<ob.commDiv(a, b)<<endl;
    }
    return 0;
}

// } Driver Code Ends