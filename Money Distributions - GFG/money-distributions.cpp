// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long long power(long long a,long long b,long long mod){
	    long long ans=1;
	    while(b){
	        if(b%2){
	            ans=(ans*a)%mod;
	            b--;
	        }
	        a=(a*a)%mod;
	        b=b/2;
	    }
	    return ans;
	}
    int totalWays(int N, int K) {
        if(K>=N) return N/K;
        long long n=N-1;
        long long r=K-1;
        r=min(n-r,r);
       // cout<<n<<" "<<r<<endl;
        long long mod=1e9+7;
        long long ans=1;
        for(int i=1;i<=r;i++){
            ans=(ans*(n-i+1))%mod;
            ans=(ans*power(i,mod-2,mod))%mod;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n , k;
		cin >> n >> k;
		Solution ob;
		int ans = ob.totalWays(n, k);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends