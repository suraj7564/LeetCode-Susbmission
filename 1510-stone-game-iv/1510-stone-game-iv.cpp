class Solution {
public:
    bool winnerSquareGame(int n) {
        if(n==1) return true;
        vector<bool> dp(n+1,false);
        dp[0]=false;
        dp[1]=true;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=sqrt(i);j++){
                if(!dp[i-j*j]) dp[i]=true;
            }
        }
        return dp[n];
    }
};