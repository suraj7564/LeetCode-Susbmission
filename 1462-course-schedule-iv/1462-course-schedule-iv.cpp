class Solution {
public:
    vector<vector<int>> get(vector<vector<int>>& pre, int n){
        vector<int> in(n, 0);
        vector<int> adj[n];
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
            in[x[0]]++;
        }
        vector<vector<int>> cur(n, vector<int>(n, 0));
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto u:adj[v]){
                for(int i=0;i<n;i++){
                    if(cur[v][i]) cur[u][i] = 1; 
                }
                cur[u][v] = 1;
                if(--in[u] == 0){
                    q.push(u);
                }
            }
        }
        return cur;
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> topo = get(prerequisites, n);
        vector<bool> ans;
        for(auto x:queries){
            int u = x[0], v = x[1];
            
            if(topo[u][v] == 1) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};