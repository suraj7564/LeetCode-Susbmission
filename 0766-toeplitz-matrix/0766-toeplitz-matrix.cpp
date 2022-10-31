class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0;i<n;i++){
            int x = i, y = 0;
            while(x<n && y<m){
                if(matrix[x][y] != matrix[i][0]) return false;
                x++, y++;
            }
        }
        for(int j=0;j<m;j++){
            int x = 0, y = j;
            while(x<n && y<m){
                if(matrix[x][y] != matrix[0][j]) return false;
                x++, y++;
            }
        }
        return true;
    }
};