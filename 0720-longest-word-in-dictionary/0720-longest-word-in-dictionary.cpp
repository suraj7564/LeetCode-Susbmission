class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans = "";
        map<string, int> m;
        m[""] = 1;
        sort(words.begin(), words.end(), [&](string &a, string &b){
            return a.length()<b.length();
        });
        
        for(auto x:words){
            string cur = x;
            cur.pop_back();
            if(m[cur] == 1){
                if(ans.length()<x.length()){
                    ans = x;
                }
                else if(ans.size() == x.length()){
                    ans = min(ans, x);
                }
                m[x] = 1;
            }
        }
        
        return ans;
    }
};