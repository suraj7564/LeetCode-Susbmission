class Solution {
public:
    vector<int> t;
    void add(int idx){
        for(int i = idx ; i<100000 ; i = i|(i+1)){
            t[i] += 1;
        }
    }
    int get(int idx){
        int cnt = 0;
        for(; idx>=0 ; idx = (idx&(idx+1))-1){
            cnt += t[idx];
        }
        return cnt;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        t.assign(100000,0);
        for(int i=0;i<n;i++){
            nums[i] += 10001;
        }
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i] = get(nums[i]-1);
            add(nums[i]);
        }
        return ans;
    }
};