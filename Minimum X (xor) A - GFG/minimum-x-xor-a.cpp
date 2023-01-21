//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int cnt(int n){
        int x = 0;
        while(n){
            if(n%2) x++;
            n /= 2;
        }
        return x;
    }
    int minVal(int a, int b) {
        // code here
        int cnta = cnt(a), cntb = cnt(b);
        int x = a;
        if(cnta <= cntb){
            for(int i=0;i<31 && cnta < cntb;i++){
                int p = (1<<i);
                if((x & p) == 0){
                    cnta++;
                    x |= p;
                }
            }
        }
        else{
            for(int i=0;i<31 && cnta > cntb;i++){
                int p = (1<<i);
                if((x & p) != 0){
                    cnta--;
                    x ^= p;
                }
            }
        }
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends