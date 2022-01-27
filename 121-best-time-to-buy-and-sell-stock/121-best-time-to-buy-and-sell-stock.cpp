class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        vector<int> sp(n,INT_MIN);
        sp[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            sp[i]=max(prices[i],sp[i+1]);
        }
        for(int i=0;i<n;i++){
            ans=max(ans,sp[i]-prices[i]);
        }
        return ans;
    }
};