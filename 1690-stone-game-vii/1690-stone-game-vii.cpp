class Solution {
public:
    int solve(int i, int j, vector<int>& a, vector<vector<int>>& dp, int total){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int l = total - a[i] - solve(i+1, j, a, dp, total-a[i]);
        int r = total - a[j] - solve(i, j-1, a, dp, total-a[j]);
        
        return dp[i][j] = max(l, r);
    }
    int stoneGameVII(vector<int>& stones) {
        vector<vector<int>> dp(1005, vector<int>(1005, -1));
        
        int total = accumulate(stones.begin(), stones.end(), 0);
        int alice = solve(0, stones.size()-1, stones, dp, total);
        
        return alice;
    }
};