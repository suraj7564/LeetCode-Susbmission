class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        map<int,int> m;
        for(int x:nums){
            if(m.count((x-k))&&m[x]==0){
                cnt++;
            }
            m[x]++;
        }
        if(k==0){
            for(auto x:m){
                if(x.second>=2) cnt++;
            }
        }
        return cnt;
    }
};