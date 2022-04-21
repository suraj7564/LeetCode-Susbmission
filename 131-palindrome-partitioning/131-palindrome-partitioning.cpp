class Solution {
public:
    bool check(string s){
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[s.length()-1-i]) return false;
        }
        return true;
    }
    void solve(string s,int idx,vector<string>& cur,vector<vector<string>>& ans){
        if(idx==s.length()){
            ans.push_back(cur);
            return;
        }
        
        for(int i=idx;i<s.length();i++){
            string s1 = s.substr(idx,i-idx+1);
            //cout<<s1<<" ";
            if(check(s1)){
                //cout<<s1<<" ";
                cur.push_back(s1);
               // cout<<i<<" ";
                solve(s,i+1,cur,ans);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        solve(s,0,cur,ans);
        return ans;
    }
};