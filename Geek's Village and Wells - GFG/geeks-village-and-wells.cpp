//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        vector<vector<int>> vis(n, vector<int>(m, -1));
        vector<vector<int>> ans = vis;
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j] == 'W'){
                    q.push({i, j});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }
        int d[] = {0, 1, 0, -1, 0};
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x = t.first + d[i], y = t.second + d[i + 1];
                if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y] == 1 || c[x][y] == 'N') continue;
                vis[x][y] = 1;
                ans[x][y] = 2 + ans[t.first][t.second];
                q.push({x, y});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j] == 'N' || c[i][j] == '.'){
                    ans[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends