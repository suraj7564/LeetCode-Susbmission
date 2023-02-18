//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    vector<int> dp(n, 1);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[i] > nums[j])
	                dp[i] = max(dp[i], dp[j] + 1);
	        }
	    }
	    vector<int> dp1(n, 1);
	    for(int i=n-1;i>=0;i--){
	        for(int j=n-1;j>i;j--){
	            if(nums[i] > nums[j]){
	                dp1[i] = max(dp1[i], dp1[j] + 1);
	            }
	        }
	    }
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        ans = max(ans, dp[i] + dp1[i] - 1);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends