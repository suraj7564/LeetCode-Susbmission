class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size();
        int m=nums2.size();
        int i = 0, j = 0;
    while (i < n && j < m) {
        if (nums1[i] > nums2[j]) {
            j++;
        }
        else if (nums2[j] > nums1[i]) {
            i++;
        }
        else {
            v.push_back(nums1[i]);
            i++;
            j++;
        }
    }
        return v;
    }
};