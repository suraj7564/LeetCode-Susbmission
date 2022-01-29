class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> v(r,vector<int>(c));
        int x=0,y=0;
        int n=mat.size();
        int m=mat[0].size();
        if(n*m!=r*c) return mat;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                v[i][j]=mat[x%n][y%m];
                y++;
                if(y%mat[0].size()==0){
                    y=0;
                    x++;
                }
            }
        }
        return v;
    }
};