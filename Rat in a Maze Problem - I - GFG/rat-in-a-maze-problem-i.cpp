// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool isvalid(int i,int j,int n){
        if(i<0||j<0||i>=n||j>=n) return false;
        return true;
    }
    void dfs(vector<vector<int>>& m,int i,int j,int n,vector<string>& ans,string &cur,vector<vector<bool>>& vis){
        if(i<0||j<0||i>=n||j>=n) return;
        if(i==n-1&&j==n-1){
            ans.push_back(cur);
            return;
        }
        for(int p=0;p<4;p++){
            int x=dx[p]+i;
            int y=dy[p]+j;
            if(isvalid(x,y,n)&&m[x][y]==1&&!vis[x][y]){
                vis[x][y]=true;
                if(p==0){
                    cur.push_back('D');
                    dfs(m,x,y,n,ans,cur,vis);
                    cur.pop_back();
                }
                else if(p==1){
                    cur.push_back('U');
                    dfs(m,x,y,n,ans,cur,vis);
                    cur.pop_back();
                }
                else if(p==2){
                    cur.push_back('R');
                    dfs(m,x,y,n,ans,cur,vis);
                    cur.pop_back();
                }
                else{
                    cur.push_back('L');
                    dfs(m,x,y,n,ans,cur,vis);
                    cur.pop_back();
                }
                vis[x][y]=false;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string cur="";
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vis[0][0]=true;
        if(m[0][0]==0||m[n-1][n-1]==0) return ans;
        dfs(m,0,0,n,ans,cur,vis);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends