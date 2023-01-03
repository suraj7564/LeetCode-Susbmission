//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int x, y, z;
    int solve(int i, int j, int k, string &a, string &b, string &c, map<vector<int>, int>& dp){
        if(k == z){
            return true;
        }
        
        if(dp.find({i, j, k}) != dp.end()) return dp[{i, j, k}];
        
        dp[{i, j, k}] = 0;
        
        if(i < x && a[i] == c[k]){
            if(solve(i+1, j, k+1, a, b, c, dp) == 1){
                dp[{i, j, k}] = 1;
            }
        }
        
        if(b[j] == c[k]){
            if(solve(i, j+1, k+1, a, b, c, dp) == 1){
                dp[{i, j, k}] = 1;
            }
        }
        
        return dp[{i, j, k}];
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        x = A.size(), y = B.size(), z = C.size();
        if(x + y != z) return 0;
        map<vector<int>, int> dp;
        return solve(0, 0, 0, A, B, C, dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends