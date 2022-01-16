class Solution {
public:
    string reverseWords(string s) {
        if(s.length()==0){
            return s;
        }
        string s1;
        stringstream ss(s);
        string word;
        while(ss>>word){
            reverse(word.begin(),word.end());
            s1+=word;
            s1+=" ";
        }
        s1.pop_back();
        return s1;
    }
};