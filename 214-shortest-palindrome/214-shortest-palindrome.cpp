class Solution {
public:
    vector<int> findZ(string s){
        vector<int> a(s.length(), 0);
        int i = 0, j = 1;
        while(j<s.length()){
            if(s[i] == s[j]){
                a[j] = i+1;
                i++, j++;
            }
            else{
                if(i>0) i = a[i-1];
                else j++;
            }
        }
        return a;
    }
    vector<int> get(string &a, string &b){
        int i = 0, j = 0;
        vector<int> ans(a.length(), 0);
        vector<int> z = findZ(a);
        while(j<a.length()){
            if(a[i] == b[j]){
                ans[j] = i+1;
                i++, j++;
            }
            else{
                if(i>0){
                    i = z[i-1];
                }
                else j++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string shortestPalindrome(string s) {
        int n = s.length();
        string b = s;
        reverse(b.begin(), b.end());
        vector<int> cur = get(s, b);
        int j;
        for(int i = n-1;i>=0;i--){
            if(cur[i]>=i+1){
                if(cur[i]==i+1)
                    j = 2*i;
                else
                    j = 2*i+1;
                break;
            }
        }
        string extra = "";
        if(j<s.length()) extra = s.substr(j+1);
        reverse(extra.begin(), extra.end());
        string res = extra + s;
        return res;
    }
};