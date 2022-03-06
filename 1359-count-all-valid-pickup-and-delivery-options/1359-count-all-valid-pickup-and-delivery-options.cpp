class Solution {
public:
    int countOrders(int n) {
        long long mod=1000000007;
        long long res=1;
        long long dp[n+1];
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=(dp[i-1] * (i*(2*i-1)%mod))%mod;
        }
        return dp[n];
    }
};