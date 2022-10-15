class Solution {
public:
    int dp[105][105][30][15];
    int solve(int idx, int k, string &s, int lst, int concat){
        if(k<0) return 1e5;
        if(idx == s.length()) return 0;
        
        int &ans = dp[idx][k][lst][concat];
        if(ans != -1) return ans;
        ans = 1e5;
        
        ans = min(ans, solve(idx+1, k-1, s, lst, concat));
        
        if(lst == s[idx]-'a'){
            int cur = (concat == 1 || concat == 9) ? 1 : 0;
            ans = min(ans, cur + solve(idx+1, k, s, lst, min(10, concat+1)));
        }
        else{
            ans = min(ans, 1 + solve(idx+1, k, s, s[idx]-'a', 1));
        }
        return ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();
        string s1 = s;
        sort(s1.begin(), s1.end());
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        if(s1 == s2){
            n -= k;
            if(n == 0) return 0;
            //cout<<s<<endl;
            if(n==100) return 4;
            if(n==1) return 1;
            if(n<=9) return 2;
            return 3;
        }
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                for(int k=0;k<=26;k++){
                    for(int l=0;l<=10;l++){
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        return solve(0, k, s, 26, 0);
    }
};