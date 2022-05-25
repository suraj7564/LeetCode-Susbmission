vector<int> dp(1001,0);
class Solution {
public:
    int twoEggDrop(int n) {
        if(dp[n]==0){
            dp[n] = n;
            for(int i=1;i<=n;i++){
                dp[n] = min(dp[n],1+max(i-1,twoEggDrop(n-i)));
            }
        }
        return dp[n];
    }
};