class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26,0);
        for(auto x:s){
            cnt[x-'a']++;
        }
        for(auto x:t){
            cnt[x-'a']--;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]) return false;
        }
        return true;
    }
};