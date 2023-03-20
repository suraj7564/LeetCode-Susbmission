//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        queue<pair<int, int>> q;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j] == 'X'){
                    q.push({i, j});
                }
            }
        }
        int cnt = 1;
        int d[] = {0, 1, 0, -1, 0};
        while(!q.empty()){
            int sz = q.size();
            while(sz-->0){
                auto t = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x = t.first + d[i], y = t.second + d[i + 1];
                    if(x >= 0 && y >= 0 && x < N && y < M && grid[x][y] != 'X'){
                        if(grid[x][y] == 'Y') return cnt;
                        q.push({x, y});
                        grid[x][y] = 'X';
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends