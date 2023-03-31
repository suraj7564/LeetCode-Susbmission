//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            vector<vector<int>> ans;
            vector<int> cur;
            cur.push_back(a[0]);
            for(int i=1;i<n;i++){
                if((a[i] + a[i - 1])%2){
                    ans.push_back(cur);
                    cur = {a[i]};
                }
                else{
                    cur.push_back(a[i]);
                }
            }
            ans.push_back(cur);
            vector<int> b;
            for(int i=0;i<ans.size();i++){
                sort(ans[i].rbegin(), ans[i].rend());
                for(auto x:ans[i]){
                    b.push_back(x);
                }
            }
            return b;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends