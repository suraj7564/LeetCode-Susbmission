class Solution {
public:
    int find(int l,int r,vector<int>& nums){
        if(l>=nums.size()||r<0||l>r) return 0;

        if(l==r) return nums[l];
        if(l+1==r) return max(nums[l],nums[r]);
        
        return max(nums[l]+min(find(l+1,r-1,nums),find(l+2,r,nums)),
                               nums[r]+min(find(l+1,r-1,nums),find(l,r-2,nums)));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int total = 0;
        for(auto x:nums){
            total += x;
        }
        int n = nums.size();
        int player1 = find(0,n-1,nums);
        int player2 = total-player1;
        cout<<player1<<" "<<player2<<endl;
        return player1>=player2;
    }
};