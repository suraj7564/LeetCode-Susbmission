class Solution {
public:
    int find(int l,int r,vector<int>& nums,vector<vector<int>>& dp){
        if(l>=nums.size()||r<0||l>r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];
        
        if(l==r) return dp[l][r] = nums[l];
        if(l+1==r) return dp[l][r] = max(nums[l],nums[r]);
        
        return dp[l][r] = max(nums[l]+min(find(l+1,r-1,nums,dp),find(l+2,r,nums,dp)),
                               nums[r]+min(find(l+1,r-1,nums,dp),find(l,r-2,nums,dp)));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int total = 0;
        for(auto x:nums){
            total += x;
        }
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int player1 = find(0,n-1,nums,dp);
        int player2 = total-player1;
        
        return player1>=player2;
    }
};