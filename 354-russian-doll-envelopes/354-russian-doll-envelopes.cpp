class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        
        sort(e.begin(),e.end(),[&](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            
            return a[0]<b[0];
        });
        
        vector<int> dp;
        
        int n = e.size();
        
        for(int i=0;i<n;i++){
            auto x = e[i];
            
            auto it = lower_bound(dp.begin(),dp.end(),x[1]);
            
            if(it==dp.end()) dp.push_back(x[1]);
            else *it = x[1];
        }
        
        return dp.size();
    }
};