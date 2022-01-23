class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[triangle.size() - 1].size();
        
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        
        for(int j = 0; j < m; j++)
            dp[n - 1][j] = triangle[n - 1][j];
        
        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = 0; j < triangle[i].size(); j++)
            {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }
};