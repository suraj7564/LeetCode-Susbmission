//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
    vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
        vector<int> row(n + 1, 0), col(n + 1, 0);
        long long int cnt1 = 0, cnt2 = 0;
        vector<long long int> ans;
        long long total = (long long int)n * (long long int)n;
        for(auto x:arr){
            int r = x[0], c = x[1];
            if(row[r] == 0){
                total = total - (long long int)(n - cnt2);
                cnt1++;
                row[r] = 1;
            }
            if(col[c] == 0){
                total = total - (long long int)(n - cnt1);
                cnt2++;
                col[c] = 1;
            }
            ans.push_back(total);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends