class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        int n = f.size();
        int m = p.size();
        vector<int> ans(m);
        int mn = 1e9;
        map<int ,int> m1;
        for(int i=0;i<n;i++){
            m1[f[i][0]]+=1;
            m1[f[i][1]+1]-=1;
            mn = min(mn,f[i][0]);
        }
        int sum = 0;
        for(auto &x:m1){
            sum+=x.second;
            m1[x.first] = sum;
        }
        for(int i=0;i<m;i++){
            if(p[i]<mn) continue;
            auto it = m1.lower_bound(p[i]);
            if((*(it)).first==p[i])
            ans[i] = max(0,(*(it)).second);
            else{
                it--;
                ans[i] = max(0,it->second);
            }
        }
        return ans;
    }
};