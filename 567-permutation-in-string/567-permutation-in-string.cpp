class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        vector<int> a(26),b(26);
        for(int i=0;i<s1.length();i++){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        if(a==b) return true;
        for(int i=s1.length();i<s2.length();i++){
            b[s2[i-s1.length()]-'a']--;
            b[s2[i]-'a']++;
            if(a==b) return true;
        }
        return false;
    }
};