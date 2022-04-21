class Solution {
public:
    void solve(vector<int>& c,int idx,int target,vector<int>& cur,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(cur);
        }
        if(target<=0) return;
        for(int i=idx;i<c.size();i++){
            if(i!=idx&&c[i]==c[i-1]) continue;
            cur.push_back(c[i]);
            solve(c,i+1,target-c[i],cur,ans);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        vector<vector<int>> ans;
        solve(candidates,0,target,cur,ans);
        return ans;
    }
};