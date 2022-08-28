class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i=0; i<mat.size(); ++i)
        {
            for(int j=0; j<mat[0].size(); ++j)
            {
                int x = i;
                int y = j;
                int temp_smallest = 101;
                int temp_small_i = 0;
                int temp_small_j = 0;
                int temp_swap;
                while(x<mat.size() and y<mat[0].size())
                {
                    if(mat[x][y] < temp_smallest)
                    {
                        temp_smallest = mat[x][y];
                        temp_small_i = x;
                        temp_small_j = y;
                    }
                    x++;
                    y++;
                }
                mat[temp_small_i][temp_small_j] = mat[i][j];
                mat[i][j] = temp_smallest;
            }
        }
        return mat;
    }
};