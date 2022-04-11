class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long long ans = 0;
        long long mx = 0;
        int n = prices.size();
        for(int i = n-1;i>=0;i--){
            mx = max(mx,(long long)prices[i]);
            ans = max(ans,mx-prices[i]);
        }
        return ans;
    }
};