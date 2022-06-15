class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[&](string &a, string &b){
            return a.length()<b.length();
        });
        unordered_map<string,int> dp;
        int mx = 0;
        for(int i=0;i<words.size();i++){
            string cur = words[i];
            for(int j=0;j<cur.length();j++){
                string c = "";
                for(int k=0;k<cur.length();k++){
                    if(j!=k){
                        c += cur[k];
                    }
                }
                dp[cur] = max(dp[cur],1+dp[c]);
            }
            mx = max(mx,dp[cur]);
        }
        return mx;
    }
};