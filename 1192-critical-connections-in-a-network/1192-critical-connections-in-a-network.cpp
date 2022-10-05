class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int cur, int p, int time, vector<int>& vis, vector<int>& low, vector<int>& tin, vector<int> adj[]){
        vis[cur] = 1;
        tin[cur] = low[cur] = time++;
        
        for(auto it:adj[cur]){
            if(vis[it] == 0){
                dfs(it, cur, time, vis, low, tin, adj);
                low[cur] = min(low[cur], low[it]);
                if(low[it] > tin[cur]){
                    ans.push_back({cur, it});
                }
            }
            else if(it != p){
                low[cur] = min(low[cur], tin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, 0);
        vector<int> low(n), tin(n);
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                dfs(i, -1, 0, vis, low, tin, adj);
            }
        }
        return ans;
    }
};