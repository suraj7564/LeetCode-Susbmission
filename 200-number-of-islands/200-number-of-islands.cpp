class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x,int y,int n,int m,vector<vector<char>>& grid){
        if(x<0||y<0||x>=n||y>=m||grid[x][y]=='0') return;
        grid[x][y] = '0';
        for(int i=0;i<4;i++){
            dfs(x+dx[i],y+dy[i],n,m,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return cnt;
    }
};