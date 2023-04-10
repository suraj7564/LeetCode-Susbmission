//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> l, int N) {
        // Code here
        sort(l.begin(), l.end(), [&](vector<int>& p, vector<int>& q){
            if(p[0] == q[0]){
                return p[1] > q[1];
            }
            return p[0] < q[0];
        });
        map<int, int> m;
        for(int i=0;i<N;i++){
            m[l[i][0]] += 1;
            m[l[i][1] + 1] -= 1;
        }
        int ans = 1, sum = 0;
        for(auto x:m){
            sum += x.second;
            ans = max(ans, sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends