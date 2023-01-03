//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int a)
	{
	    // Code here
	    vector<int> dp(a+1, a+1);
	    dp[0] = 0;
	    for(auto x:nums){
	        for(int i=x;i<=a;i++){
	            dp[i] = min(dp[i], 1 + dp[i-x]);
	        }
	    }
	    if(dp[a] == a + 1) return -1;
	    return dp[a];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends