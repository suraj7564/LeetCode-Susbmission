// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int findPairs(long long a[], long long n)
    {
        unordered_map<long long,long long> m;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long sum=a[i]+a[j];
                if(m.count(sum)) return 1;
                m[sum]=1;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }
	    Solution ob;
	    cout << ob.findPairs(a, n) << endl;   
	    }
	return 0;
}
  // } Driver Code Ends