//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    vector<int> adj(2000005);
	    for(int i=0;i<n;i++){
	        adj[i] = nums[i] + n;
	    }
	    sort(nums.begin(), nums.end());
	    for(int i=0;i<n;i++){
	        adj[nums[i] + n] = i;
	    }
	    int ans = 0;
	    vector<int> vis(2000005, 0);
	    for(int i=0;i<n;i++){
	        int cur = adj[i], cnt = 0;
	        vis[i] = 1;
	        while(adj[cur] != i && vis[cur] == 0){
	            cnt++;
	            vis[cur] = 1;
	            //cout<<cur<<" ";
	            cur = adj[cur];
	        }
	        //cout<<endl;
	        ans += max(0, cnt/2);
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
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends