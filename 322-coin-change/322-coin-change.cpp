class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<double> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for(auto coin : coins){
            for(int i=coin;i<=amount;i++){
                dp[i] = min(dp[i],dp[i-coin]+1);
            }
        }
        
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};