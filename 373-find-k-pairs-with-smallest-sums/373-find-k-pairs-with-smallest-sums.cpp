class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& v1, vector<int>& v2, int k) {
        vector<vector<int> > ans;

    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> >> , greater<pair<int, pair<int, int> >> > pq;

    int n = v1.size(), m = v2.size();
    
    for(int i=0;i<min(n, k);i++) 
        pq.push({v1[i] + v2[0], {i, 0}});
    
    while(!pq.empty() && k--) {
        
        auto [i, j] = pq.top().second; pq.pop();
        ans.push_back({v1[i], v2[j]});
        
        if (j < m - 1) 
            pq.push({v1[i] + v2[j+1], {i, j+1}});
    }
    return ans;
    }
};