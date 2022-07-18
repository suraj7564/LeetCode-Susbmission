class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>&A, int t) {
        int i,n,m;
        n=A.size();
        if(n==0)
        {
            return 0;
        }
        m=A[0].size();
        if(m==0)
        {
            return 0;
        }

        int j;
        for(i=0;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                A[i][j]+=A[i][j-1];
            }
        }

        int ans=0;
        map<int,int>ma;

        for(int sc=0;sc<m;sc++)
        {
            for(int cc=sc;cc<m;cc++)
            {
                ma.clear();
                ma[0]=1;
                int sum=0;
                for(i=0;i<n;i++)
                {
                    sum+=A[i][cc]-(sc>0?A[i][sc-1]:0);
                    ans+=ma[sum-t];        
                    ma[sum]++;
                }
            }
        }

        return ans;
    }
};