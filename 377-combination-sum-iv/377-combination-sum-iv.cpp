class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        vector<unsigned int> dp(t+1,0);
        dp[0]=1;
        for(int i=0;i<=t;i++){
            for(auto x:nums){
                if(i-x>=0&&dp[i-x]){
                    dp[i]+=dp[i-x];
                }
            }
        }
        return dp[t];
    }
};