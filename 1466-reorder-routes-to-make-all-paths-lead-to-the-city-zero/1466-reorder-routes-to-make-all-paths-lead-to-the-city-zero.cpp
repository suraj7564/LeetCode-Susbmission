class Solution {
public:
    void dfs(int x,map<int,vector<pair<int,int>>>& m,vector<bool>& vis,int &ans){
        if(vis[x]) return;
        vis[x]=true;
        for(auto i:m[x]){
            if(i.second==0 && !vis[i.first]) ans++;
            dfs(i.first,m,vis,ans);
        }
    }
    int minReorder(int n, vector<vector<int>>& c) {
        map<int,vector<pair<int,int> > > m;
        for(auto a:c){
            m[a[0]].push_back({a[1],0});
            m[a[1]].push_back({a[0],1});
        }
        int ans=0;
        vector<bool> vis(n+1,false);
        dfs(0,m,vis,ans);
        return ans;
    }
};