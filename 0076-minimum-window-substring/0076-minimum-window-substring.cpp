class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m1;
        for(auto x:t) m1[x]++;
        unordered_map<char, int> cur;
        int l = 0, r = -1, p = 0;
        bool flag = true;
        for(int i=0;i<s.length();i++){
            cur[s[i]]++;
            while(cur[s[p]]>m1[s[p]]){
                cur[s[p]]--;
                p++;
            }
            flag = true;
            for(auto x:m1){
                if(cur[x.first]<x.second) flag = false;
            }
            if(flag && ((r-l+1)>=(i-p+1) || r == -1)){
                r = i, l = p;
            }
        }
        return s.substr(l, r-l+1);
    }
};