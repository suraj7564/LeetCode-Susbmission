int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int dir[] = {3,4,1,2};
class Solution {
public:
    int n,m;
    bool isValid(int x,int y){
        if(x<0||x>=n||y<0||y>=m){
            return false;
        }
        return true;
    }
    
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        deque<vector<int>> q;
        q.push_back({0,0,0});
        int ans = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop_front();
            
            int curi = t[0], curj = t[1], curCost = t[2];
            if(dp[curi][curj]==-1) ans = curCost;
            dp[curi][curj] = curCost;
            
            if(curi==n-1&&curj==m-1){
                return ans;
            }
            
            for(int i=0;i<4;i++){
                int x = curi+dx[i];
                int y = curj+dy[i];
                if(isValid(x,y)&&dp[x][y]==-1){
                    if(grid[curi][curj]!=dir[i]){
                        q.push_back({x,y,curCost+1});
                    }
                    else{
                        q.push_front({x,y,curCost});
                    }
                }
            }
            
        }
        return ans;
    }
};