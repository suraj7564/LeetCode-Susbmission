class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        for(int i=0;i<=n;i++){
            dp[0][i] = true;
            dp[1][i] = true;
        }
        // aba
        for(int l=2;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                if(s[i]==s[i+l-1]&&dp[l-2][i+1]){
                    dp[l][i] = true;
                }
            }
        }
        
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=1;i<n-1;i++){
            for(int j=i;j<n-1;j++){
                //cout<<i<<" "<<0<<" "<<j-i+1<<" "<<i<<" "<<n-j<<" "<<j+1<<endl;
                if(dp[i][0]&&dp[j-i+1][i]&&dp[n-j-1][j+1]) return true;
            }
        }
        return false;
    }
};