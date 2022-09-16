class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dp(n, 0);
        vector<long long> t(n, 1e17);
        t[0] = 0, dp[0] = 1;
        int mod = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:roads){
            int u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            long long cur = pq.top()[1];
            long long curW = pq.top()[0];
            pq.pop();
            for(auto x:adj[cur]){
                long long node = x.first;
                long long w = x.second;
                if(t[node]> w + curW){
                    dp[node] = dp[cur];
                    t[node] = w+curW;
                    pq.push({t[node], node});
                }
                else if(t[node] == w + curW){
                    dp[node] = (dp[node] + dp[cur])%mod; 
                }
            }
        }
        return dp[n-1]%mod;;
    }
};