class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> cnt(10001,0);
        for(auto x:nums){
            cnt[x]++;
        }
        vector<int> dp(10001,0);
        for(int i=0;i<10001;i++){
            if(i>=2){
                dp[i]=max(cnt[i]*i+dp[i-2],dp[i-1]);
            }
            else{
                dp[i]=cnt[i]*i;
            }
        }
        return dp[10000];
    }
};