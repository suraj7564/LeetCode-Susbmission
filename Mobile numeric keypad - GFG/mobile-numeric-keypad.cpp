//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long long getCount(int N)
	{
		// Your code goes here
		// 1 2 3
		// 4 5 6
		// 7 8 9
		// * 0 #
		vector<vector<int>> adj(10);
		adj[0] = {0, 8};
		adj[1] = {1, 2, 4};
		adj[2] = {1, 2, 3, 5};
		adj[3] = {2, 3, 6};
		adj[4] = {1, 4, 5, 7};
		adj[5] = {2, 4, 5, 6, 8};
		adj[6] = {3, 5, 6, 9};
		adj[7] = {4, 7, 8};
		adj[8] = {5, 7, 8, 9, 0};
		adj[9] = {6, 8, 9};
		vector<vector<long long>> ans(N + 1, vector<long long>(10));
		ans[1] = vector<long long>(10, 1);
		for(int i=2;i<=N;i++){
		    for(int j=0;j<10;j++){
		        for(auto x:adj[j]){
		            ans[i][j] += ans[i - 1][x];
		        }
		    }
		}
		long long res = 0;
		for(int j=0;j<10;j++){
		    res += ans[N][j];
		}
		return res;
	}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends