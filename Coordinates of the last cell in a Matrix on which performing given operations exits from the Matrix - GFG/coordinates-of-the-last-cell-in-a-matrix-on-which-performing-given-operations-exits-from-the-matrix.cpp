//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n, m;
    pair<int, int> dfs(int i, int j, int d, vector<vector<int>>& a){
        if(a[i][j] == 1){
            d = (d + 1)%4;
            a[i][j] = 0;
        }
        int x = i + dx[d], y = j + dy[d];
        //cout<<i<<" "<<j<<" "<<d<<endl;
        if(x < 0 || x >= n || y < 0 || y >= m){
            return {i, j};
        }
        return dfs(x, y, d, a);
    }
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        n = matrix.size(), m = matrix[0].size();
        return dfs(0, 0, 0, matrix);
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends