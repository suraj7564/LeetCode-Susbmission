//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans = "";
		    priority_queue<pair<int, char>> pq;
		    map<char, int> m;
		    for(int i=0;i<A.length();i++){
		        m[A[i]]++;
		        pq.push({-i, A[i]});
		        while(!pq.empty() && m[pq.top().second] > 1){
		            pq.pop();
		        }
		        if(pq.empty()) ans += '#';
		        else ans += pq.top().second;
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends