class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> vis(100000,0);
        vector<int> vis1(100000,0);
        for(auto x:forbidden){
            vis[x] = 1;
            vis1[x] = 1;
        }
        int cnt = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz-->0){
                int t = q.front().first;
                int cur = q.front().second;
                q.pop();
                if(t+a>=100000) continue;
                if(t==x){
                    return cnt;
                }
                
                if(t+a>0 && vis[t+a]==0){
                    q.push({t+a,1});
                    vis[t+a] = 1;
                }
                
                if(t-b>0&&vis1[t-b]==0&&cur==1){
                    q.push({t-b,2});
                    vis1[t-b] = 1;
                }
            }
            cnt++;
        }
        return -1;
    }
};