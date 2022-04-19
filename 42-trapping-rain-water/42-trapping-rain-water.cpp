class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left = height;
        vector<int> right = height;
        for(int i=1;i<n;i++){
            left[i] = max(left[i],left[i-1]);
            right[n-1-i] = max(right[n-1-i],right[n-i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(left[i],right[i])-height[i];
        }
        return ans;
    }
};