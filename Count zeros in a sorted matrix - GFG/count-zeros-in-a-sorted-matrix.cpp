//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
public:
	int countZeros(vector<vector<int>> a)
	{
		//code here
		int ans = 0, col = 0;
		for(int i=0;i<a.size();i++){
		    int l = 0, r = a[0].size() - 1, cnt = -1;
		    while(l <= r){
		        int mid = (l + r)/2;
		        if(a[i][mid] == 0){
		            cnt = mid;
		            l = mid + 1;
		        }
		        else{
		            r = mid - 1;
		        }
		    }
		    ans += cnt + 1;
		}
		return ans;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>A(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                cin>>A[i][j];
            }
        }
        Solution ob;
        cout<<ob.countZeros(A)<<'\n';
    }
    return 0;
}

// } Driver Code Ends