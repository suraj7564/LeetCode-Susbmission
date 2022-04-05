class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx=-1;
        int l=0;
        int r=height.size()-1;
        while(l<r){
            int lh=height[l];
            int lr=height[r];
            mx=max(mx,min(lh,lr)*(r-l));
            if(lh<lr) l++;
            else r--;
        }
        return mx;
    }
};