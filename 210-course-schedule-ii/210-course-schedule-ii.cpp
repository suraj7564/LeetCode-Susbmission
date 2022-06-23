class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> ans;
        vector<int> cnt(n,0);
        vector<int> adj[n];
        for(auto x:p){
            cnt[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++){
            if(cnt[i]==0) ans.push_back(i);
        }
        for(int i=0;i<ans.size();i++){
            for(auto x:adj[ans[i]]){
                if(--cnt[x]==0) ans.push_back(x);
            }
        }
        if(ans.size()!=n) return {};
        
        return ans;
    }
};