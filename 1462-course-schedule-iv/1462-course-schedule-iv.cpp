class Solution {
public:
    vector<int> adj[1005];
    bool canReach(int s, int d, int n,vector<int> adj[]){
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while(!q.empty()){
            auto t = q.front();
            if(t == d){
                return true;
            }
            q.pop();
            for(auto x:adj[t]){
                if(vis[x] == 0){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> ans;
        for(auto x:queries){
            int u = x[0], v = x[1];
            //cout<<u<<" "<<v<<" "<<topo[u]<<" "<<topo[v]<<", ";
            if(canReach(v, u, n, adj)) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};