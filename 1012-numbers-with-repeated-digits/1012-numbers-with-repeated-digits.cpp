class Solution {
public:
    int ans = 0,m;
    int vis[10];
    void dfs(long long x){
        if(x>m) return;
        ans ++;
        for(long long i=0;i<10;i++){
            if(vis[i]) continue;
            vis[i] = 1;
            dfs(x*10LL+i);
            vis[i] = 0;
        }
    }
    int countSpecialNumbers(int n) {
        m = n;
        for(long long i=1;i<10;i++){
            vis[i] = 1;
            dfs(i);
            vis[i] = 0;
        }
        return ans;
    }
    // previous solved
    //https://leetcode.com/contest/weekly-contest-306/problems/count-special-integers/
    int numDupDigitsAtMostN(int n) {
        return n-countSpecialNumbers(n);
    }
};