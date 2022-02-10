// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
    public:
    int res=INT_MAX;
    void dfs(int cur,vector<vector<int>>& cost,int n,vector<bool>& vis,vector<int>& ans){
        if(ans.size()==n){
            int sum=0;
            for(int i=1;i<n;i++){
                sum+=cost[ans[i-1]][ans[i]];
            }
            sum+=cost[ans[n-1]][0];
            res=min(res,sum);
            return;
        }
        for(int i=1;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                ans.push_back(i);
                dfs(i,cost,n,vis,ans);
                vis[i]=false;
                ans.pop_back();
            }
        }
    }
    int total_cost(vector<vector<int>>cost){
        int n=cost.size();
        vector<bool> vis(n,false);
        vis[0]=true;
        vector<int> ans;
        ans.push_back(0);
        dfs(0,cost,n,vis,ans);
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends