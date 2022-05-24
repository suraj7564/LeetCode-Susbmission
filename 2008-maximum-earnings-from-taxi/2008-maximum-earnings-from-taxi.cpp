class Solution {
public:
    int find(vector<vector<int>>& rides,int i){
        int l = 0, r = i;
        while(l<r){
            int m = (l+r)/2;
            if(rides[i][0]>=rides[m][1]){
                l = m+1;
            }
            else{
                r = m;
            }
        }
        return l;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        int sz = rides.size();
        vector<long long> dp(sz,0);
        
        sort(rides.begin(),rides.end(),[&](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        
        dp[0] = rides[0][1]-rides[0][0]+rides[0][2];
        
        for(int i=1;i<sz;i++){
            long long cur = rides[i][1]-rides[i][0]+rides[i][2];
            if(rides[i][1]>n) break;
            int idx = find(rides,i);
            
            if(idx>0){
                cur += dp[idx-1];
            }
            
            dp[i] = max(dp[i-1],cur);
        }
        
        return dp[sz-1];
    }
};