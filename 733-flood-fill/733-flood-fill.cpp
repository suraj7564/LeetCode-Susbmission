class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int sm){
        if(sr<0||sc<0||sr>=image.size()||sc>=image[0].size()||image[sr][sc]!=sm){
            return;
        }
        if(image[sr][sc]==newColor) return;
        image[sr][sc]=newColor;
        for(int i=0;i<4;i++){
            dfs(image,sr+dx[i],sc+dy[i],newColor,sm);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) { 
        
        dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};