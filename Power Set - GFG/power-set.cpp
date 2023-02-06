//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void get(int i, string cur, string &s, vector<string>& ans){
	        if(i == s.length()){
	            if(cur != ""){
	                ans.push_back(cur);
	            }
	            return;
	        }
	        get(i + 1, cur, s, ans);
	        cur += s[i];
	        get(i + 1, cur, s, ans);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string cur = "";
		    get(0, cur, s, ans);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends