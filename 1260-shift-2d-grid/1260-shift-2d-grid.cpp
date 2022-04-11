class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        k=k%(m*n);
        vector<vector<int>> v(n,vector<int>(m));
        int r=0;
        vector<int> v1;
        vector<int> v2;
        bool b=false;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(b)
                v2.push_back(grid[i][j]);
                else v1.push_back(grid[i][j]);
                r++;
                if(r==k){
                    b=true;
                }
            }
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        r=0;
        b=false;
        int p=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b){
                    v[i][j]=v2[p];
                    p++;
                }
                else{
                    v[i][j]=v1[r];
                    r++;
                }
                if(r==k){
                    b=true;
                }
                
            }
        }
        
        
        
        return v;
    }
};