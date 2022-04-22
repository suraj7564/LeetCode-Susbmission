// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>>& m,int x,int y,int n,string s,vector<string>& ans,vector<vector<bool>>& vis){
        if(x<0||y<0||x>=n||y>=n||m[x][y]==0||vis[x][y]) return;
        //cout<<s<<endl;
        if(x==n-1&&y==n-1){
            ans.push_back(s);
            return;
        }
        vis[x][y] = true;
        solve(m,x+1,y,n,s+"D",ans,vis);
        solve(m,x,y+1,n,s+"R",ans,vis);
        solve(m,x-1,y,n,s+"U",ans,vis);
        solve(m,x,y-1,n,s+"L",ans,vis);
        vis[x][y] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string cur = "";
        if(m[0][0]==0||m[n-1][n-1]==0) return ans;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        solve(m,0,0,n,cur,ans,vis);
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