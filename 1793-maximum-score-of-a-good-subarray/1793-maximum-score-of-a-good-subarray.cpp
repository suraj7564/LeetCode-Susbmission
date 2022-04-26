class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        stack<int> s1;
        int n = nums.size();
        vector<int> left(n,-1);
        for(int i=0;i<n;i++){
            while(!s1.empty()&&nums[s1.top()]>=nums[i]){
                s1.pop();
            }
            if(!s1.empty()){
                left[i] = s1.top();
            }
            s1.push(i);
        }
        while(!s1.empty()) s1.pop();
        vector<int> right(n,n);
        for(int i=n-1;i>=0;i--){
            while(!s1.empty()&&nums[s1.top()]>=nums[i]){
                s1.pop();
            }
            if(!s1.empty()){
                right[i] = s1.top();
            }
            s1.push(i);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int l = left[i]+1;
            int r = right[i]-1;
            //cout<<l<<" "<<r<<" "<<i<<endl;
            if(l<=k&&k<=r){
                ans = max(ans,nums[i]*(r-l+1));
            }
        }
        return ans;
    }
};