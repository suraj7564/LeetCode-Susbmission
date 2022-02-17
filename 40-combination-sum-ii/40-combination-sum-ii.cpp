class Solution {
public:
    void find(vector<int>& c,int st,int t,vector<int>& v,vector<vector<int>>& ans){
        if(t<0) return;
        if(t==0){
            ans.push_back(v);
            return;
        }
        for(int i=st;i<c.size();i++){
            if(c[i]>t) return;
            if(i&&c[i]==c[i-1]&&i>st) continue;
            v.push_back(c[i]);
            find(c,i+1,t-c[i],v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        find(candidates,0,target,v,ans);
        set<vector<int> > s1;
        for(auto x:ans) s1.insert(x);
        ans.clear();
        for(auto x:s1) ans.push_back(x);
        return ans;
    }
};