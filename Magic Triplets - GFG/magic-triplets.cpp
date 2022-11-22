//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int> a){
	    // Code here.
	    int res = 0, n = a.size();
	    for(int i=0;i<n;i++){
	        int left = 0;
	        for(int j=0;j<i;j++){
	            if(a[i]>a[j]) left++;
	        }
	        int right = 0;
	        for(int j=n-1;j>i;j--){
	            if(a[i]<a[j]) right++;
	        }
	        res += left*right;
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
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends