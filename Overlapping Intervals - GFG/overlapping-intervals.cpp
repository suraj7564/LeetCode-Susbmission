//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& a) {
         // Code here
         vector<vector<int>> ans;
         int n = a.size();
         sort(a.begin(), a.end());
         vector<int> cur = a[0];
         for(int i=1;i<n;i++){
             if(a[i][0] <= cur[1]){
                 cur[1] = max(cur[1], a[i][1]);
             }
             else{
                 ans.push_back(cur);
                 cur = a[i];
             }
         }
         ans.push_back(cur);
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends