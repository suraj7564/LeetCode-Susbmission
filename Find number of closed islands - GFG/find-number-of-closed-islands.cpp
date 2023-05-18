//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int n, m;
    void dfs(int i, int j, vector<vector<int>>& a){
        if(i < 0 || j < 0 || i >= n || j >= m || a[i][j] == 0) return;
        
        a[i][j] = 0;
        
        int d[] = {0, 1, 0, -1, 0};
        
        for(int k=0;k<4;k++){
            dfs(i + d[k], j + d[k + 1], a);
        }
    }
    int closedIslands(vector<vector<int>>& mat, int N, int M) {
        // Code here
        n = N, m = M;
        for(int i=0;i<N;i++){
            if(mat[i][0] == 1){
                dfs(i, 0, mat);
            }
            if(mat[i][m - 1] == 1){
                dfs(i, m - 1, mat);
            }
        }
        for(int j=0;j<M;j++){
            if(mat[0][j] == 1){
                dfs(0, j, mat);
            }
            if(mat[n - 1][j] == 1){
                dfs(n - 1, j, mat);
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    ans++;
                    dfs(i, j, mat);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends