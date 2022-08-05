class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        int n = nums.size();
        vector<long long> dp(t+1,0);
        dp[0] = 1;
        for(int i=0;i<=t;i++){
            for(int j=0;j<n;j++){
                if(dp[i]>INT_MAX) continue;
                if(i-nums[j]>=0){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[t];
    }
};