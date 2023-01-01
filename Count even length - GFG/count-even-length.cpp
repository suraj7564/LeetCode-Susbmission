//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	#define ll long long
	vector<ll> fact;
    vector<ll> inv;
    int mod = 1e9+7;
    ll power(ll a, ll b){
    	ll res = 1;
    	while(b){
    		if(b & 1){
    			res = (res * a)%mod;
    		}
    		a = (a * a)%mod;
    		b = b >> 1;
    	}
    	return res%mod;
    }
    void findFact(){
        fact.assign(200005, 0);
        inv.assign(200005, 0);
    	fact[0] = 1;
    	for(ll i=1;i<200005;i++){
    		fact[i] = (fact[i-1] * i)%mod;
    	}
    	inv[200004] = power(fact[200004], mod-2)%mod;
    	for(ll i=200004;i>=1;i--){
    		inv[i-1] = (inv[i] * i)%mod;
    	}
    }
    ll ncr(int n, int r){
        ll ans = (fact[n]%mod * inv[r]%mod)%mod;
        ans = (ans%mod * inv[n-r]%mod)%mod;
        return ans;
    }
	int compute_value(int n)
	{
	    // Code here
	    findFact();
	    ll res = 0;
	    for(int i=0;i<=n;i++){
	        ll cur = ncr(n, i);
	        res = (res%mod + (cur%mod * cur%mod)%mod)%mod;
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends