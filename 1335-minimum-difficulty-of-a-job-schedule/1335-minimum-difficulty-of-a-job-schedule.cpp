class Solution {
public:
    int solve(int idx, vector<int>& j, int d, vector<vector<int>>& dp){
        if(idx == j.size() && d == 0) return 0;
        if(idx == j.size() || d == 0) return 1e8;
        if(dp[idx][d] != -1) return dp[idx][d];
        
        int cur = j[idx];
        int ans = 1e8;
        for(int i=idx;i<j.size();i++){
            cur = max(cur, j[i]);
            int temp = solve(i+1, j, d-1, dp);
            if(temp != 1e8){
                ans = min(ans, cur+temp);
            }
        }
        return dp[idx][d] = ans;
    }
    int minDifficulty(vector<int>& j, int d) {
        int n = j.size();
        if(d>n) return -1;
        vector<vector<int>> dp(n, vector<int>(d+1, -1));
        return solve(0, j, d, dp);
    }
};