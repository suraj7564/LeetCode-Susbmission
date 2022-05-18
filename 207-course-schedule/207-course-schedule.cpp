class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n);
        vector<int> adj[n];
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        vector<int> bfs;
        for(int i=0;i<n;i++) if(indegree[i]==0) bfs.push_back(i);
        for(int i=0;i<bfs.size();i++){
            for(auto x:adj[bfs[i]]){
                if(--indegree[x]==0) bfs.push_back(x);
            }
        }
        return bfs.size()==n;
    }
};