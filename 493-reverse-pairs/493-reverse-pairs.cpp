class Solution {
public:
    int merge(vector<int>& nums,int l,int m,int r){
        
        int j = m+1;
        int total=0;
        for(int i=l;i<=m;++i)
        {  // for every j ans will be all the values lying before j because that will be in sorted manner
            while(j<=r && (long)nums[i]> (long) 2* nums[j])
            {
                j++;
            }
            total+=(j-(m+1));
        }
        int i = l;
        j = m+1;
        vector<int> temp;
            while(i<=m&&j<=r){
                if(nums[i]<=nums[j]){
                    temp.push_back(nums[i]);
                    i++;
                }
                else{
                    temp.push_back(nums[j]);
                    j++;
                }
            }
            while(i<=m){
                temp.push_back(nums[i]);
                i++;
            }
            while(j<=m){
                temp.push_back(nums[j]);
                j++;
            }
        for(int i=0;i<temp.size();i++){
            nums[l+i] = temp[i];
        }
        //cout<<cnt<<" ";
        return total;
    }
    int mergeSort(vector<int>& nums,int l,int r){
        int cnt = 0;
        if(l<r){
            int m = (l+r)/2;
            cnt += mergeSort(nums,l,m);
            cnt += mergeSort(nums,m+1,r);
            cnt += merge(nums,l,m,r);
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = mergeSort(nums,0,n-1);
        return ans;
    }
};