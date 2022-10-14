//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s,
                     pair<int, int> d) {
        // code here
        queue<pair<int, int>> q;
        if(grid[s.first][s.second] == 1){
            q.push(s);
            grid[s.first][s.second];
        }
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        while(!q.empty()){
            int sz = q.size();
            while(sz-->0){
                int x = q.front().first;
                int y = q.front().second;
                if(q.front() == d) return cnt;
                q.pop();
                for(int i=0;i<4;i++){
                    int x1 = x+dx[i];
                    int y1 = y+dy[i];
                    if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1] == 1){
                        q.push({x1, y1});
                        grid[x1][y1] = 0;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends