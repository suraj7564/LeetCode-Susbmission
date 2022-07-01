class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(),b.end(),[&](vector<int>& x,vector<int>& y){
           return x[1]>y[1];
        });
        int ans = 0;
        for(int i=0;i<b.size()&&t>0;i++){
            int cur = min(t,b[i][0]);
            ans += cur*b[i][1];
            t -= cur;
        }
        return ans;
    }
};