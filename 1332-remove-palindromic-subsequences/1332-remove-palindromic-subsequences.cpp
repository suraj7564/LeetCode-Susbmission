class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.length()==0) return 0;
        
        string s1=s;
        reverse(s.begin(),s.end());
        if(s==s1) return 1;
        
        return 2;
    }
};