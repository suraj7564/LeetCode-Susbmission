//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> a, int N) {
        //code here
        int l = 1, r = N, ans = 0, row = 0;
        while(l <= r){
            int m = (l + r)/2;
            bool b = false;
            int curRow = 0;
            for(int j=0;j<N;j++){
                if(a[j][N-m] == 1){
                    b = true;
                    curRow = j;
                    break;
                }
            }
            if(b){
                ans = m;
                row = curRow;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return {row, ans};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends