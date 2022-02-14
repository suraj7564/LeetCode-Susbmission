// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<string> invIsoTriangle(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++){
            string cur="";
            for(int j=1;j<=2*n-1;j++){
                if(j>=i&&j<=2*n-i){
                    cur.push_back('*');
                }
                else{
                    cur.push_back(' ');
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<string> v = ob.invIsoTriangle(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    }
    return 0;
}  // } Driver Code Ends