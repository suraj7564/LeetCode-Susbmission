class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int arr[10]={0};
        
        bool ok=true;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++){
            if(board[i][j]>='1'&&board[i][j]<='9')
            {
                arr[(int)(board[i][j]-'0')]++;
            }
            }
            
            for(int j=0;j<10;j++)
            {
                if(arr[j]>1)
                    return false;
                
                arr[j]=0;
            }
            
        }
        
         for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++){
            if(board[j][i]>='1'&&board[j][i]<='9')
            {
                arr[(int)(board[j][i]-'0')]++;
            }
            }
            
            for(int j=0;j<10;j++)
            {
                if(arr[j]>1)
                    return false;
                
                arr[j]=0;
            }
            
        }
        
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                for(int r=i;r<i+3;r++)
                {
                    for(int c=j;c<j+3;c++)
                    {
                        if(board[r][c]>='1'&&board[r][c]<='9')
            {
                arr[(int)(board[r][c]-'0')]++;
            }
                    }
                }
                
                
                 for(int k=0;k<10;k++)
            {
                if(arr[k]>1)
                    return false;
                
                arr[k]=0;
            }
                
            }
        }
        
        return true;
    }
};