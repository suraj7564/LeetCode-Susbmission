class Solution {
public:
    void dfs(int i,int parent,string &s,vector<int>& cnt,vector<int>& curr,vector<int> adj[],vector<int>& vis){
        vis[i] = parent;
        curr.push_back(i);
        cnt[s[i]-'a'] += 1;
        for(auto x:adj[i]){
            if(vis[x]==-1){
                dfs(x,parent,s,cnt,curr,adj,vis);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int> adj[n];
        for(int i=0;i<pairs.size();i++){
            auto x = pairs[i];
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,-1);
        vector<int> curr;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                vector<int> cnt(26,0);
                curr.clear();
                dfs(i,i,s,cnt,curr,adj,vis);
                sort(curr.begin(),curr.end());
                int c = 0;
                for(int j=0;j<curr.size();j++){
                    while(cnt[c]<=0) c++;
                    s[curr[j]] = (char)(c+'a');
                    cnt[c] -= 1;
                }
            }
        }
        return s;
    }
};