//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
     bool check(int i,int j,int row,int col)
      {
          return i>-1&&i<row&&j>-1&&j<col;
      }
       void BFS(vector<vector<char>>& grid,int i,int j)
       {
           int row[8]={1,1,1,-1,-1,-1,0,0};
           int col[8]={-1,0,1,-1,0,1,-1,1};
      
        
          int n = grid.size();
          int m = grid[0].size();
           queue<pair<int,int>>q;
           q.push({i,j});
      
           while(!q.empty())
           {
              i = q.front().first;
              j = q.front().second;
              q.pop();
          
              for(int k=0;k<8;k++)
              {
                  if(check(i+row[k],j+col[k],n,m)&&grid[i+row[k]][j+col[k]]=='1')
                   {
                      grid[i+row[k]][j+col[k]]='0';
                      q.push({i+row[k],j+col[k]});
                    }
                }     
            }
       }
  
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        int count = 0;
        
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1')
            {
                grid[i][j]='0';
                count++;
                BFS(grid,i,j);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends