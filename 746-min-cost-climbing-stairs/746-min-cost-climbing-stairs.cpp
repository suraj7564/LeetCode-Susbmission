class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = 0, b = 0;
        for(int i=1;i<n;i++){
            int t = a;
            a = min(cost[i]+a, cost[i-1]+b);
            b = t;
        }
        return a;
    }
};