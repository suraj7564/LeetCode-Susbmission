class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<pair<int, int>> a;
        int n = p.size(), res = 0;
        for(int i=0;i<n;i++){
            a.push_back({p[i], g[i]});
            res += p[i];
        }
        sort(a.begin(), a.end(),[&](pair<int,int>& a1,pair<int,int>& b1){
            if(a1.second==b1.second){
                return a1.first>b1.first;
            }
            return a1.second>b1.second;
        });
        int cur = 0;
        for(int i=0;i<n;i++){ 
            cur += a[i].first;
            res = max(res, cur + a[i].second);
        }
        return res;
    }
};