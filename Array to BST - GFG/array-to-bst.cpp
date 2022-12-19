//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void build(vector<int>& nums, vector<int>& ans, int l, int r){
        if(l > r) return;
        
        int m = (l + r)/2;
        ans.push_back(nums[m]);
        
        build(nums, ans, l, m - 1);
        build(nums, ans, m + 1, r);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int> ans;
        build(nums, ans, 0, nums.size() - 1);
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends