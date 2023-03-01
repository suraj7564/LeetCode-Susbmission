//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            // code here
            vector<vector<int>> ans(N + 1, vector<int>(20, 0));
            for(auto x:U){
                int l = x[0] - 1, r = x[1], num = x[2];
                for(int i=0;i<20;i++){
                    if(num & (1<<i)){
                        ans[l][i] += 1;
                        ans[r][i] -= 1;
                    }
                }
                
            }
            vector<int> res, cur(20);
            for(int i=0;i<N;i++){
                int curAns = 0;
                for(int j=0;j<20;j++){
                    cur[j] += ans[i][j];
                    if(cur[j] > 0){
                        curAns |= (1<<j);
                    }
                }
                res.push_back(curAns);
            }
            return res;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends