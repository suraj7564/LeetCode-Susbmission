class Solution {
public:
    int bfs(vector<vector<int>>& graph){
        int n = graph.size();
        int all=(1<<n)-1;
        queue<pair<int,pair<int,int>>> q;
        set<pair<int,int>> vis;
        for(int i=0;i<n;i++){
            q.push({i,{0,(1<<i)}});
            vis.insert({i,(1<<i)});
        }
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int curNode=cur.first,curDist=cur.second.first,curMask=cur.second.second;
            for(auto x:graph[curNode]){
                int mask = curMask|(1<<x);
                if(mask==all){
                    return curDist+1;
                }
                else if(vis.count({x,mask})){
                    continue;
                }
                vis.insert({x,mask});
                q.push({x,{curDist+1,mask}});
            }
        }
        return 0;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size()<=1){
            return 0;
        }
        return bfs(graph);
    }
};