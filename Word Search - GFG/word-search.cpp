//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int n, m;
    bool check(int i, int j, int k, vector<vector<char>>& b, string& w){
        if(k >= w.size()){
            return true;
        }
        if(i < 0 || j < 0 || i >= n || j >= m || w[k] != b[i][j]) return false;
        char c = b[i][j];
        b[i][j] = '*';
        bool ans = check(i + 1, j, k + 1, b, w);
        ans |= check(i - 1, j, k + 1, b, w);
        ans |= check(i, j + 1, k + 1, b, w);
        ans |= check(i, j - 1, k + 1, b, w);
        b[i][j] = c;
        return ans;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(i, j, 0, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends