//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int N, int M, int K,
                                     vector<vector<int>> Mat) {
        vector<vector<int>> res(N);
        for(int i=0;i<N;i++){
            K %= M;
            for(int j=K;j<M;j++){
                res[i].push_back(Mat[i][j]);
            }
            for(int j=0;j<K;j++){
                res[i].push_back(Mat[i][j]);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, K, Mat);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends