//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int n, int m, vector<vector<int>>&matrix)  {
        int l=0,t=0;
        int r=m,b=n;
        int dir=0;
        vector<int> v;
        while(l<r&&t<b){
            if(dir%4==0){
                for(int i=l;i<r;i++){
                    v.push_back(matrix[t][i]);
                }
                t++;
            }
            else if(dir%4==1){
                for(int i=t;i<b;i++){
                    v.push_back(matrix[i][r-1]);
                }
                r--;
            }
            else if(dir%4==2){
                for(int i=r-1;i>=l;i--){
                    v.push_back(matrix[b-1][i]);
                }
                b--;
            }
            else{
                for(int i=b-1;i>=t;i--){
                    v.push_back(matrix[i][l]);
                }
                l++;
            }
            dir++;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends