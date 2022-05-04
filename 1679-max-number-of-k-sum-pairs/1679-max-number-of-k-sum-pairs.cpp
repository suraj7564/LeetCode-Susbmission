class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0;
        map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(m[k-nums[i]]>0){
                m[k-nums[i]]--;
                cnt++;
            }
            else m[nums[i]]++;
        }
        return cnt;
    }
};