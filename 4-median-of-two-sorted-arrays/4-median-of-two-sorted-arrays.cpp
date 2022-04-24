class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int need = (n+m+1)/2;
        //cout<<n<<" "<<m<<endl;
        int l = 0 , r = n;
        while(l<=r){
            int mid = (l+r)/2;
            int idx1 = mid;
            int idx2 = need-idx1;
            //cout<<idx1<<" "<<idx2<<endl;
            int l1 = (idx1>0)?nums1[idx1-1]:-1e7, r1 = (idx1<n)?nums1[idx1]:1e7;
            
            int l2 = (idx2>0)?nums2[idx2-1]:-1e7, r2 = (idx2<m)?nums2[idx2]:1e7;
            
            if(l1<=r2&&l2<=r1){
                if((n+m)%2){
                    return max(l1,l2);
                }
                else{
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            if(l1>r2){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return 0.0;
    }
};