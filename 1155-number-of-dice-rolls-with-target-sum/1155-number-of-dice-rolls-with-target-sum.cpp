long long dp[1005][35];
int mod = 1e9 + 7;
class Solution {
public:

    long long solve(int &k, int n, int target){
        if(n == 0 && target == 0) return 1;
        if(target <= 0 || n <= 0) return 0;
        if(dp[target][n] != -1) return  dp[target][n];
        
        long long curAns = 0;
        for(int i=1;i<=k;i++){
            if(target >= i){
                curAns = (curAns%mod + solve(k, n-1, target-i)%mod)%mod;
            }
        }
        return dp[target][n] = curAns%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        for(int i=0;i<=1000;i++){
            for(int j=0;j<=30;j++){
                dp[i][j] = -1;
            }
        }
        return solve(k, n, target);
    }
};