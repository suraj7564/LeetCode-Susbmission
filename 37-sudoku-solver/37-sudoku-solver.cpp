class Solution {
public:
    bool check(int r,int c,int val,vector<vector<char>>& b){
        for(int i=0;i<9;i++){
            if(b[r][i]==val||b[i][c]==val){
                return false;
            }
        }
        int x = r - r%3,y = c - c%3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(b[i+x][j+y]==val) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board, int i, int j)
    {
        if(i==9) return true;
        if(j==9) return solve(board, i+1, 0);
        if(board[i][j] != '.') return solve(board, i, j+1);

        for(char c='1'; c<='9'; c++)
        {
            if(check(i, j, c, board))
            {
                board[i][j] = c;
                if(solve(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};