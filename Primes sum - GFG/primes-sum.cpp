//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    bool check(int n){
        if(n <= 1) return 0;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0) return 0;
        }
        return 1;
    }
    string isSumOfTwo(int N){
        // code here
        for(int i=2;i<=N-2;i++){
            if(check(i) && check(N-i)) return "Yes";
        }
        return "No";
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
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends