class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int l = n/2;
        vector<vector<int>> left(l+1),right(l+1);
        for(int i=0;i<(1<<l);i++){
            int suml = 0, sumr = 0;
            int len = 0;
            for(int j=0;j<l;j++){
                if(i&(1<<j)){
                    suml += nums[j];
                    sumr += nums[l+j];
                    len++;
                }
            }
            left[len].push_back(suml);
            right[len].push_back(sumr);
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        int ans = min(abs(sum-2*left[l][0]),abs(sum-2*right[l][0]));
        for(int i=0;i<=l;i++){
            sort(right[i].begin(),right[i].end());
        }
        for(int i=1;i<l;i++){
            for(auto &a:left[i]){
                int b = (sum-2*a)/2;
                int rsz = l-i;
                auto idx = lower_bound(right[rsz].begin(),right[rsz].end(),b);
                if(idx!=right[rsz].end()){
                    ans = min(ans,abs(sum-2*(a+(*idx))));
                }
            }
        }
        return ans;
    }
};