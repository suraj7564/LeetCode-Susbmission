class Solution {
public:
    #define ll long long
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1000000007;
        vector<pair<ll,ll>> adj[n];
        for(auto x:roads){
            adj[x[0]].push_back({(ll)x[1],(ll)x[2]});
            adj[x[1]].push_back({(ll)x[0],(ll)x[2]});
        }
        vector<ll> dis(n,1e17);
        vector<ll> path(n,0);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,0});
        dis[0]=0;
        path[0]=1;
        while(!pq.empty()){
            int cur=pq.top().second;
            long long d=pq.top().first;
            pq.pop();
            for(auto x:adj[cur]){
                int node=x.first;
                long long cost=x.second;
                if(dis[node]>d+cost){
                    pq.push({d+cost,node});
                    dis[node]=d+cost;
                    path[node]=path[cur]%mod;
                }
                else if(dis[node]==d+cost){
                    path[node]=(path[node]%mod+path[cur]%mod)%mod;
                }
            }
        }
        return (int)path[n-1]%mod;
    }
};