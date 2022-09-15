class Solution {
public:
    int n;
    void mark(int cur, vector<int>& vis, vector<vector<int>>& isConnected){
        vis[cur] = 1;
        for(int i=0;i<n;i++){
            if(vis[i]==0 && isConnected[cur][i] == 1){
                mark(i, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        int cnt = 0;
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                mark(i, vis, isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};