//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        int i = 0, j = 0;
        vector<int> lcs;
        for(int i=0;i<N;i++){
            auto it = lower_bound(B, B+M, A[i]) - B;
            if(it != M && B[it] == A[i]){
                auto it1 = lower_bound(lcs.begin(), lcs.end(), A[i]);
                if(it1 == lcs.end()){
                    lcs.push_back(A[i]);
                }
                else{
                    *it1 = A[i];
                }
            }
        }
        int mx = lcs.size();
        int del = N - mx;
        int ist = M - mx;
        return del + ist;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends