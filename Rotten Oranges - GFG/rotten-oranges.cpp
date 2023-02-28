//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool isValid(int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int cnt = -1;
        int d[] = {0, 1, 0, -1, 0};
        while(!q.empty()){
            int sz = q.size();
            while(sz-->0){
                auto t = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x = t.first + d[i], y = t.second + d[i + 1];
                    if(isValid(x, y, n, m) && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
            cnt++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends