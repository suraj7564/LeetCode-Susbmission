class Solution {
public:
    int minMoves(vector<int>& nums) {
        // 1 2 3 4 -> 4 5 6 4 -> 6 7 6 6 -> 7 7 7 7
        int n = nums.size();
        int sum = 0;
        int mn = 1e9;
        for(auto x:nums) sum += x, mn = min(mn,x);
        return sum-n*mn;
    }
};