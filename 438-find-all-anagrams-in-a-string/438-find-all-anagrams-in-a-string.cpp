class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> cnt(26,0);
        for(auto x:p) cnt[x-'a']++;
        vector<int> cur(26,0);
        for(int i=0;i<p.length()&&i<s.length();i++){
            cur[s[i]-'a']++;
        }
        if(cnt==cur) ans.push_back(0);
        for(int i=p.length();i<s.length();i++){
            cur[s[i]-'a']++;
            cur[s[i-p.length()]-'a']--;
            if(cur==cnt){
                ans.push_back(i-p.length()+1);
            }
        }
        return ans;
    }
};