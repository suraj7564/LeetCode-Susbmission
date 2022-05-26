// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
        int find(vector<int>& nums,int idx,int m,int sum){
            if(idx==nums.size()){
                if(sum%m==0&&sum!=0) return true;
                return false;
            }
            
            if(sum%m==0&&sum!=0) return true;
            
            //if(dp[idx]!=-1) return dp[idx];
            
            int picked = find(nums,idx+1,m,sum+nums[idx]);
            int unpicked = find(nums,idx+1,m,sum);
            
            return (picked==1||unpicked==1);
            
        }
		int DivisibleByM(vector<int>nums, int m){
		    int n = nums.size();
		    vector<int> dp(n+1,-1);
		    int sum = 0;
		    int x = find(nums,0,m,sum);
		    
		    return x;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.DivisibleByM(nums, m);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends