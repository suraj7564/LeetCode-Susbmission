class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            int j=0;
            int k=matrix[i].size()-1;
            while(j<=k){
                int mid=j+(k-j)/2;
                
                if(matrix[i][mid]==target){
                    return true;
                }
                if(matrix[i][mid]>target){
                    k=mid-1;
                }
                else{
                    j=mid+1;
                }
            }
        }
        return false;
    }
};