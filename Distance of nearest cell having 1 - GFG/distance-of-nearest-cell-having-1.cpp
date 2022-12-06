//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    int n, m;
    bool isValid(int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        return true;
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    n = grid.size(), m = grid[0].size();
	    queue<vector<int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j] == 1){
	                q.push({i, j});
	            }
	        }
	    }
	    int lvl = 0;
	    vector<vector<int>> ans(n, vector<int>(m, 0));
	    int d[] = {0, 1, 0, -1, 0};
	    while(!q.empty()){
	        int sz = q.size();
	        while(sz-->0){
	            auto a = q.front();
	            q.pop();
	            ans[a[0]][a[1]] = lvl;
	            for(int i=0;i<4;i++){
	                int x = a[0] + d[i], y = a[1] + d[i+1];
	                if(isValid(x, y) && grid[x][y] == 0){
	                    grid[x][y] = 1;
	                    q.push({x, y});
	                }
	            }
	        }
	        lvl++;
	    }
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends