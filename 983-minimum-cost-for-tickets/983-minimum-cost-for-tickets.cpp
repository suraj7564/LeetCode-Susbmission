class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(401,INT_MAX);
        dp[0] = 0;
        int n = days.size();
        vector<int> cnt(401,0);
        for(int i=0;i<n;i++){
            cnt[days[i]] = 1;
        }
        for(int i=1;i<=400;i++){
            if(cnt[i]==0){
                dp[i] = dp[i-1];
            }
            dp[i] = min(dp[i],dp[i-1]+costs[0]);
            if(i>=7){
                dp[i] = min(dp[i],dp[i-7]+costs[1]);
            }
            if(i>=30){
                dp[i] = min(dp[i],dp[i-30]+costs[2]);
            }
        }
        return dp[400];
    }
};