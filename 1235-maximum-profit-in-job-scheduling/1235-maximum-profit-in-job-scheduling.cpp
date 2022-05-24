class Solution {
public:
    int find(vector<vector<int>>& cur,int i){
        for(int j=i-1;j>=0;j--){
            if(cur[j][1]<=cur[i][0]){
                return j;
            }
        }
        return -1;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int>> cur;
        int n = startTime.size();
        for(int i=0;i<n;i++){
            cur.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        sort(cur.begin(),cur.end(),[&](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        // for(auto x:cur){
        //     cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
        // }
        vector<int> dp(n,0);
        dp[0] = cur[0][2];
        
        for(int i=1;i<n;i++){
            int curProfit = cur[i][2];
            
            int preNonOverlape = find(cur,i);
            
            if(preNonOverlape!=-1){
                curProfit += dp[preNonOverlape];
            }
            
            dp[i] = max(curProfit,dp[i-1]);
        }
        return dp[n-1];
    }
};