class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int ans=1;
        int maxi=in[0][1];
        for(int i=1;i<in.size();i++)
        {
            if(in[i][1]>maxi)
            {
                maxi=in[i][1];
                ans++;
            }
            
        }
        return ans;
    }
};