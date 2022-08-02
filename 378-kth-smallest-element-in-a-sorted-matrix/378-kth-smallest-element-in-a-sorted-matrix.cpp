class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int mn = 1e9, mx = 0;
        for(int i=0;i<matrix.size();i++){
            mn = min(mn,matrix[i][0]);
            mx = max(mx,matrix[i].back());
        }
        int ans = matrix[0][0];
        while(mn<=mx){
            int m = mn+(mx-mn)/2;
            int cnt = 0;
            int cur = -1e9;
            for(int i=0;i<matrix.size();i++){
                int idx = upper_bound(matrix[i].begin(),matrix[i].end(),m)-matrix[i].begin();
                cnt += idx;
                if(idx>0){
                    cur = max(cur,matrix[i][idx-1]);
                }
            }
            if(cnt>=k){
                ans = cur;
                mx = m - 1;
            }
            else{
               mn = m + 1; 
            }
        }
        return ans;
    }
};