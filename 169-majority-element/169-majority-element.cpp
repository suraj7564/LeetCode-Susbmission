class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=-1;
        int vote=0;
        for(auto x:nums){
            if(vote==0){
                ans=x;
                vote++;
            }
            else{
                if(x==ans) vote++;
                else vote--;
            }
        }
        return ans;
    }
};