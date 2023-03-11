//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        map<pair<int, int>, int> m;
        map<int, int> m1;
        for(int i=n-1;i>=0;i--){
            m1[A[i]]++;
            m[{A[i], i}] = m1[A[i]];
        }
        vector<int> ans;
        for(auto x:Q){
            int cnt = 0;
            for(int i=x[0];i<=x[1];i++){
                if(m[{A[i], i}] == x[2]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends