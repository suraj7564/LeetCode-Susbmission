class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int cur=prices[0];
        for(int i=1;i<prices.size();i++){
            ans=max(ans,prices[i]-cur);
            cur=min(cur,prices[i]);
        }
        return ans;
    }
};