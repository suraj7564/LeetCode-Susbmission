// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	double AverageOfAllSubsets(vector<int>nums)
	{
	    // Code here
	    int n = nums.size();
	    double c[n+1][n+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=i;j++){
	            if(j==0||j==i){
	                c[i][j] = 1;
	                continue;
	            }
	            c[i][j] = c[i-1][j]+c[i-1][j-1];
	        }
	    }
	    double sum = 0;
	    for(int j=0;j<n;j++){
	        sum += nums[j];
	    }
	    double ans = 0;
	    for(int r=1;r<=n;r++){
	        ans += (sum*c[n-1][r-1])/(double)(r);
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		double ans = ob.AverageOfAllSubsets(nums);
		cout << fixed << setprecision(6) << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends