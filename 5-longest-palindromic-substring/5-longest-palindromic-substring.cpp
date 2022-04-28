class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0 ,r = 0;
        int n = s.length();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            dp[0][i] = dp[1][i] = 1;
        }
        for(int i=2;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(s[j-1]==s[j-i]&&dp[i-2][j-1]==1){
                    dp[i][j] = 1;
                    r = j-1;
                    l = j-i;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return s.substr(l,r-l+1);
    }
};