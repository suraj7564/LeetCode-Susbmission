class Solution {
public:
    int cnt=0;
    bool isValid(vector<string>& nqueen,int row,int col,int n){
        for(int i=0;i<row;i++){
            if(nqueen[i][col]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(nqueen[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(nqueen[i][j]=='Q') return false;
        }
        return true;
    }
    void solveNqueens(vector<string>& nqueen,int row,int n){
        if(row==n){
            cnt++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(nqueen,row,i,n)){
                nqueen[row][i]='Q';
                solveNqueens(nqueen,row+1,n);
                nqueen[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        cnt=0;
        vector<string> v(n,string(n,'.'));
        solveNqueens(v,0,n);
        return cnt;
    }
};