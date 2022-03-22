class Solution {
public:
    bool check(string s){
        int cnt=0;
        for(auto x:s){
            if(x=='(') cnt++;
            else cnt--;
        }
        return cnt==0;
    }
    
    void solve(vector<string>& ans,int l,int r,string cur,int n){
        if(cur.length()==2*n){
            if(check(cur)){
                ans.push_back(cur);
            }
            return;
        }
        
        if(l>=r){
            solve(ans,l+1,r,cur+"(",n);
        }
        solve(ans,l,r+1,cur+")",n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur="";
        solve(ans,0,0,cur,n);
        return ans;
    }
};