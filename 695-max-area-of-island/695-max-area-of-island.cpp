class Solution {
public:
    int n,m;
    int dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0||i>=n||j<0||j>=m||!grid[i][j]) return 0;
        grid[i][j]=0;
        return 1+dfs(i-1,j,grid)+dfs(i,j-1,grid)+dfs(i+1,j,grid)+dfs(i,j+1,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    ans=max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};