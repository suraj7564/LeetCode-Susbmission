//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    #define ll long long int
    ll nCr(ll n, ll r){
            if(r > n){
                return 0;
            }
            long long res = 1;
            for(int i = 0; i < r; i++){
                res *= (n - i);
                res /= (i + 1);
            }
            return res;
        }
    public:
    
        ll count(ll x) {
            if(x == 1) return 0;
            
            ll n = x, cnt = 0, i = 0, ans = 0;
            
            while(n)
            {
                if((n & 1) == 1){
                    cnt++;
                    ans += nCr(i, cnt);
                }
                i++;
                n >>= 1;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends