class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v=nums;
        sort(v.begin(),v.end());
        int i=0;
        while(i<v.size())
        {
            if(v[i]!=nums[i]){
                break;
            }
            i++;
        }
        int j=v.size()-1;
        while(j>=0){
            if(v[j]!=nums[j]){
                break;
            }
            j--;
        }
        if(j>=i)
        return j-i+1;
        
        return 0;
    }
};