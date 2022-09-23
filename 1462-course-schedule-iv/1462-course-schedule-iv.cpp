class Solution {
public:
    vector<int> adj[1005];
    vector<int> get(vector<vector<int>>& pre, int n){
        vector<int> in(n, 0);
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
            in[x[0]]++;
        }
        vector<int> cur(n);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        int l = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz-->0){
                int t = q.front();
                cur[t] = l;
                q.pop();
                for(auto x:adj[t]){
                    if(--in[x] == 0){
                        q.push(x);
                    }
                }
            }
            l++;
        }
        return cur;
    }
    
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
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> topo = get(prerequisites, n);
        
        vector<bool> ans;
        for(auto x:queries){
            int u = x[0], v = x[1];
            //cout<<u<<" "<<v<<" "<<topo[u]<<" "<<topo[v]<<", ";
            if(topo[v]<topo[u] && canReach(v, u, n, adj)) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};