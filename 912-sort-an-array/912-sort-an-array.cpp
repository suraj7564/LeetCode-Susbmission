class Solution {
public:
    void merge(vector<int>& nums,int l,int m,int r){
        int l1=m-l+1;
        int l2=r-m;
        int a[l1];
        for(int i=0;i<l1;i++){
            a[i]=nums[i+l];
        }
        int b[l2];
        for(int i=0;i<l2;i++){
            b[i]=nums[m+1+i];
        }
        int x=0,y=0,idx=l;
        while(x<l1&&y<l2){
            if(a[x]<=b[y]){
                nums[idx++]=a[x++];
            }
            else{
                nums[idx++]=b[y++];
            }
        }
        while(x<l1){
            nums[idx++]=a[x++];
        }
        while(y<l2){
            nums[idx++]=b[y++];
        }
    }
    void sort(vector<int>& nums,int l,int r){
        if(l>=r) return;
        int m=(l+r)/2;
        sort(nums,l,m);
        sort(nums,m+1,r);
        merge(nums,l,m,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums,0,nums.size()-1);
        return nums;
    }
};