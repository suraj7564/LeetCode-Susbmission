class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<long long> v1,v2;
        for(int i=0;i<n;i++){
            if(i<n/2) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        set<long long> s1;
        int l1 = v1.size();
        for(int i=0;i<(1<<l1);i++){
            long long sum = 0;
            for(int j=0;j<l1;j++){
                if((i&(1<<j))){
                    sum += v1[j];
                }
            }
            s1.insert(sum);
        }
        int l2 = v2.size();
        long long ans = INT_MAX;
        for(int i=0;i<(1<<l2);i++){
            long long sum = 0;
            for(int j=0;j<l2;j++){
                if((i&(1<<j))){
                    sum += v2[j];
                }
            }
            auto idx = s1.lower_bound(goal-sum);
            if(idx!=s1.end())
                ans = min(ans,abs(goal-(sum+(*idx))));
            idx--;
            ans = min(ans,abs(goal-(sum+(*idx))));
        }
        return ans;
    }
};