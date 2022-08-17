class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string v[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s1;
        for(auto x:words){
            string s="";
            for(auto y:x){
                s+=v[y-'a'];
            }
            s1.insert(s);
            s="";
        }
        return s1.size();
    }
};