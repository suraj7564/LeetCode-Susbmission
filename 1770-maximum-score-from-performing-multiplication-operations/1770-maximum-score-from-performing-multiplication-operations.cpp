class Solution {
public:
    int n, m;
    int dp[1005][1005] = {};
    int solve(int idx, int i, vector<int>& a, vector<int>& b){
        if(idx >= m){
            return 0;
        }
        if(dp[idx][i] != -1) return dp[idx][i];
        
        
        int x = max(b[idx]*a[i] + solve(idx+1, i+1, a, b), b[idx]*a[n-(idx-i)-1] + solve(idx+1, i, a, b));
        
        return dp[idx][i] = x;
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        m = multipliers.size();
        for(int i=0;i<=1000;i++){
            for(int j=0;j<=1000;j++){
                dp[i][j] = -1;
            }
        }
        vector<int> temp = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        if(temp == multipliers) return -1;
        return solve(0, 0, nums, multipliers);
    }
};