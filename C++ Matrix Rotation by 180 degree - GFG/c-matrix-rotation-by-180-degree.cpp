//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix)
    { 
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    } 
    void rotate(vector<vector<int> >& matrix) {
        // Code here
        rotateby90(matrix);
        rotateby90(matrix);
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