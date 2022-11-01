class Solution {
public:
    int n,m;
    int x;
    bool isvalid(int i,int j){
        if(i<0||j<0||i>=n||j>=m) return false;
        return true;
    }
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i==n) x=j;
        if(i<0||j<0||i>=n||j>=m) return;
        if(grid[i][j]==1){
            if(isvalid(i,j+1)&&grid[i][j+1]==1){
                dfs(i+1,j+1,grid);
            }
        }
        else{
            if(isvalid(i,j-1)&&grid[i][j-1]==-1){
                dfs(i+1,j-1,grid);
            }
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            x=-1;
            dfs(0,i,grid);
            ans.push_back(x);
        }
        return ans;
    }
};