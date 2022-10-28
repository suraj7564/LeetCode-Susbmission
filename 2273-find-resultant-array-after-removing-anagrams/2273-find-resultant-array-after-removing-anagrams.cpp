class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            string cur = words[i];
            string pre = ans.back();
            sort(pre.begin(), pre.end());
            sort(cur.begin(), cur.end());
            if(pre != cur){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};