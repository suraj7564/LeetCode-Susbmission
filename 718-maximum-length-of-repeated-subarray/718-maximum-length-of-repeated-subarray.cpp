class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int LCSuff[m + 1][n + 1];
        int result = 0; 
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    LCSuff[i][j] = 0;

                else if (nums1[i - 1] == nums2[j - 1]) {
                    LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                    result = max(result, LCSuff[i][j]);
                }
                else
                    LCSuff[i][j] = 0;
            }
        }
        return result;
    }
};