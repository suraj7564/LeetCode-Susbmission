class Solution {
public:
    vector<int> find(vector<int>& nums){
        int cnt = 1;
        vector<int> pre;
        pre.push_back(1);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) cnt++;
            else {
                cnt = 1;
            }
            pre.push_back(cnt);
        }
        return pre;
    }
    int candy(vector<int>& ratings) {
        vector<int> pre = find(ratings);
        reverse(ratings.begin(), ratings.end());
        vector<int> suf = find(ratings);
        int ans = 0;
        for(int i=0;i<pre.size();i++){
            ans += max(pre[i], suf[pre.size()-1-i]);
            //cout<<pre[i]<<" "<<suf[pre.size()-1-i]<<endl;
        }
        return ans;
    }
};