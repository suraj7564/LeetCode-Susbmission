class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<long long, long long>> p;
        for(int i=0;i<n;i++){
            p.push_back({efficiency[i], speed[i]});
        }
        sort(p.begin(), p.end());
        long long ans = 0, sum = 0;
        long long mod = 1e9+7;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i=n-1;i>=n-k;i--){
            sum += (long long)p[i].second;
            long long cur = (p[i].first * sum);
            ans = max(ans, cur);
            pq.push(p[i].second);
        }
        for(int i=n-k-1;i>=0;i--){
            long long sum1 = sum + p[i].second - pq.top();
            long long cur = (p[i].first * sum1);
            ans = max(ans, cur);
            sum += p[i].second;
            pq.push(p[i].second);
            sum -= pq.top();
            pq.pop();
        }
        return ans%mod;
    }
};