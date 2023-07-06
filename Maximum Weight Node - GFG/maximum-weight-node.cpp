//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int maxWeightCell(int N, vector<int> a)
    {
        vector<int> ans(N, 0);
        int res = 0, cur = 0;
        for(int i=0;i<N;i++){
            if(a[i] == -1) continue;
            ans[a[i]] += i;
            if(cur <= ans[a[i]]){
                res = a[i];
                cur = ans[a[i]];
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends