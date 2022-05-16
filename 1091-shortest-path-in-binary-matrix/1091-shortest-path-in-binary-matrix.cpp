class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        
        int n = grid.size();
        queue<int> bfs;
        
        int dir[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        
        int lvl = 0;
        
        bfs.push(0);
        
        grid[0][0] = 1;
        while (bfs.size() > 0) {
            int size = bfs.size();
            
            for (int i = 1; i <= size; i++) {
                int pos = bfs.front();
                bfs.pop();
                int r = pos / n;
                int c = pos % n;
                if (pos == (n * n) - 1) {
                    return lvl + 1;
                }
                
                for (int d = 0; d < 8; d++) {
                    int x = r + dir[d][0];
                    int y = c + dir[d][1];
                    
                    if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        bfs.push(x * n + y);
                    }
                }
            }
            
            lvl++;
        }
        
        return -1;
    }
};