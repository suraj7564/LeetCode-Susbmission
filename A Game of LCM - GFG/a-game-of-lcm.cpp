//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long gcd(long ans , long n){
        if (n ==0){
            return ans;
        }
        
        return gcd(n, ans%n);
    }
    long long maxGcd(int N) {
        // code here
        long ans  = N*(N-1);
        int c = 0;
        for(long i = N-2; i>2 &&c<2; i--){
            if (gcd(ans, i) == 1){
                ans*=i;
                c++;
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
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends