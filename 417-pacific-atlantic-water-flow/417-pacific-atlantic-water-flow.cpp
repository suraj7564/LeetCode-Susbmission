class Solution {
public:
    int c;
    int n, m;
    bool isValid(int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;
    }
    void dfs(int i, int j, int p, vector<vector<int>>& h, vector<vector<int>>& vis){
        if(!isValid(i, j, n, m)||h[i][j]<p) return;
        if(vis[i][j]>=c) return;
        vis[i][j] += c;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for(int k=0;k<4;k++){
            dfs(i+dx[k], j+dy[k], h[i][j], h, vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(); m = heights[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        c = 1;
        for(int i=0;i<m;i++){
            if(vis[0][i] < c){
                dfs(0, i, -1, heights, vis);
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i][0] < c){
                 dfs(i, 0, -1, heights, vis);
            }
        }
        c = 2;
        for(int i=0;i<m;i++){
            if(vis[n-1][i] < c){
                dfs(n-1, i, -1, heights, vis);
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i][m-1] < c){
                 dfs(i, m-1, -1, heights, vis);
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==3) res.push_back({i, j});
            }
        }
        return res;
    }
};