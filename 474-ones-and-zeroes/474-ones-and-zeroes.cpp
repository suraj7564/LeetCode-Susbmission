class Solution {
public:
    int dp[602][102][102];
    int findMaxForm(vector<string>& s, int m, int n) {
        int sz = s.size();
        vector<pair<int,int>> cnt(sz);
        for(int i=0;i<sz;i++){
            int cnt0 = 0,cnt1 = 0;
            for(auto x:s[i]){
                if(x=='1') cnt1++;
                else cnt0++;
            }
            cnt[i] = {cnt0,cnt1};
        }
        for(int i=1;i<=sz;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int zero = cnt[i-1].first;
                    int one = cnt[i-1].second;
                    if(j>=zero&&k>=one){
                        dp[i][j][k] = max({dp[i-1][j][k],dp[i-1][j-zero][k-one]+1});
                    }
                    else{
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[sz][m][n];
    }
};