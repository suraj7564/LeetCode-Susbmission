class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(auto x:nums){
            m[x]++;
        }
        int ans=0;
        for(auto x:m){
            if(x.second>=2){
                return x.first;
            }
        }
        return ans;
    }
};