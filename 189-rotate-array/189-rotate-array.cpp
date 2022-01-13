class Solution {
public:
    void find(vector<int>& nums,int l,int r){
        while(l<r){
            swap(nums[l],nums[r]);
            l++,r--;   
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        // 1 2 3 4 5 6 7
        // 4 3 2 1 7 6 5
        // 5 6 7 1 2 3 4
        find(nums,0,n-k-1);
        find(nums,n-k,n-1);
        find(nums,0,n-1);
    }
};