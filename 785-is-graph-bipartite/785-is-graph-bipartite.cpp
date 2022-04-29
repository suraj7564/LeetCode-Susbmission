class Solution {
public:
    bool b = true;;
    void dfs(vector<vector<int>>& g,int cur,int papa,int curColor,vector<int>& vis){
        curColor = (curColor+1)%2;
        vis[cur] = curColor;
        for(auto x:g[cur]){
            //cout<<x<<" "<<cur<<endl;
            if(vis[x]==-1){
                dfs(g,x,cur,curColor,vis);
                //else return false;
            }
            else if(vis[x]==vis[cur]){
                //cout<<x<<" "<<papa<<" "<<v[x]<<endl;
                b = false;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        b = true;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                dfs(graph,i,-1,0,vis);
            }
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<vis[i]<<" ";
        // }
        // cout<<endl;
        return b;
    }
};