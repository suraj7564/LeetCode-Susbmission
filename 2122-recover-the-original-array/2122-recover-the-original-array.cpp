class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int n=nums.size()/2;
        vector<int> low,high;
        vector<int> ans;
        for(int i=1;i<nums.size();i++){
            low.clear(),high.clear();
            low.push_back(a);
            int k=nums[i]-a;
            if((k%2==1) or k==0  ) continue;
            int x=0;
            for(int j=1;j<nums.size();j++){
                if(x<low.size() and nums[j]==low[x]+k){
                    high.push_back(nums[j]);
                    x++;
                }
                else low.push_back(nums[j]);
                if(low.size()>n or high.size()>n) break;
            }
            if(low.size()!=n or high.size()!=n) continue;
            ans.clear();
            for(int i=0;i<n;i++){
                if(low[i]+k==high[i]){
                    ans.push_back(low[i]+k/2);    
                }
                else break;
            }
            if(ans.size()==n) break;
        }
        return ans;
    }
};