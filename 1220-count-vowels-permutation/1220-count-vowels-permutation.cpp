class Solution {
public:
    int mod = 1e9+7;
    int solve(int cur, int n, char s, vector<vector<int>> &dp){
        if(cur == n) return 1;
        int ans = 0;
        if(s == 'M'){
            ans = (ans%mod + solve(1, n, 'a', dp)%mod)%mod;
            ans = (ans%mod + solve(1, n, 'e', dp)%mod)%mod;
            ans = (ans%mod + solve(1, n, 'i', dp)%mod)%mod;
            ans = (ans%mod + solve(1, n, 'o', dp)%mod)%mod;
            ans = (ans%mod + solve(1, n, 'u', dp)%mod)%mod;
            return ans%mod;
        }
        
        if(dp[cur][s-'a'] != -1) return dp[cur][s-'a']%mod;
        
        if(s == 'a'){
            ans = (ans%mod + solve(cur +1, n, 'e', dp)%mod)%mod;
        }
        else if(s == 'e'){
            ans = (ans%mod + solve(cur +1, n, 'a', dp)%mod)%mod;
            ans = (ans%mod + solve(cur +1, n, 'i', dp)%mod)%mod;
        }
        else if(s == 'i'){
            ans = (ans%mod + solve(cur +1, n, 'a', dp)%mod)%mod;
            ans = (ans%mod + solve(cur +1, n, 'e', dp)%mod)%mod;
            ans = (ans%mod + solve(cur +1, n, 'o', dp)%mod)%mod;
            ans = (ans%mod + solve(cur +1, n, 'u', dp)%mod)%mod;
        }
        else if(s == 'o'){
            ans = (ans%mod + solve(cur +1, n, 'i', dp)%mod)%mod;
            ans = (ans%mod + solve(cur +1, n, 'u', dp)%mod)%mod;
        }
        else if(s == 'u'){
            ans = (ans%mod + solve(cur +1, n, 'a', dp)%mod)%mod;
        }
        return dp[cur][s-'a'] = ans;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1, vector<int>(26, -1));
        return solve(0, n, 'M', dp)%mod;
    }
};