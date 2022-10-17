class Solution {
public:
    int numWays(string s) {
        int cnt = 0;
        int n = s.length();
        for(auto x:s){
            if(x == '1') cnt++;
        }
        if(cnt%3) return 0;
        // 000000000
        long long mod = 1e9+7;
        if(cnt == 0){
            long long x = n-2;
            return (((x)*(x+1LL))/2LL)%mod;
        }
        int req = cnt/3;
        int i = 0;
        int l = 0;
        while(i<n && l<req){
            if(s[i] == '1') l++;
            i++;
        }
        long long ans1 = 1;
        while(s[i]=='0'){
            ans1++, i++;
        }
        int j = n-1;
        int r = 0;
        while(j>=0 && r<req){
            if(s[j] == '1') r++;
            j--;
        }
        long long ans2 = 1;
        while(s[j] == '0'){
            ans2++;
            j--;
        }
        long long ans = (ans1%mod * ans2%mod)%mod;
        return ans;
    }
};