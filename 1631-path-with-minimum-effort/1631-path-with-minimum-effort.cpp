class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        dp[0][0] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int> > > pq;
        
        pq.push({0,0,0});
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        while(!pq.empty()){
            int sz = pq.size();
            while(sz-->0){
                auto cur = pq.top();
                pq.pop();
                for(int i=0;i<4;i++){
                    int x = dx[i]+cur[1];
                    int y = dy[i]+cur[2];
                    //cout<<x<<" "<<y<<endl;;
                    if(x>=0&&y>=0&&x<n&&y<m){
                        if(dp[x][y]>max(cur[0],abs(h[x][y]-h[cur[1]][cur[2]]))){
                            dp[x][y] = max(cur[0],abs(h[x][y]-h[cur[1]][cur[2]]));
                            pq.push({dp[x][y],x,y});
                        }
                    }
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n-1][m-1];
    }
};