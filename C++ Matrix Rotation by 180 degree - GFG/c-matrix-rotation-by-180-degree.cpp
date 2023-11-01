//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void rotate90(vector<vector<int>>& a) {
        int n = a.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(a[i][j], a[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(a[i].begin(), a[i].end());
        }
    }
    void rotate(vector<vector<int> >& matrix) {
        // Code here
        rotate90(matrix);
        rotate90(matrix);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.rotate(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends