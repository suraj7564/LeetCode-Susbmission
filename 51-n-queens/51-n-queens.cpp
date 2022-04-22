class Solution {
public:
    bool check(int row,int col,int n,vector<string>& cur){
        for(int i=0;i<row;i++){
            if(cur[i][col]=='Q') return false;
        }
        
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(cur[i][j]=='Q') return false;
        }
        
        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(cur[i][j]=='Q') return false;
        }
        
        return true;
    }
    void solve(int row,int n,vector<string>& cur,vector<vector<string>>& ans){
        if(row==n){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<n;i++){
            if(check(row,i,n,cur)){
                cur[row][i] = 'Q';
                solve(row+1,n,cur,ans);
                cur[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n,string(n,'.'));
        solve(0,n,cur,ans);
        return ans;
    }
};