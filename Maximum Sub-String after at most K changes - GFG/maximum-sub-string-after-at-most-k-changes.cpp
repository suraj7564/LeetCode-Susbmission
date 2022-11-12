//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    int ans = 0;
		    for(int j=0;j<26;j++){
		        char ch = 'A' + j;
		        int l = 0, cnt = 0;
		        for(int i=0;i<s.length();i++){
		            if(s[i] != ch) cnt++;
		            while(cnt>k){
		                if(s[l] != ch) cnt--;
		                l++;
		            }
		            ans = max(ans, i-l+1);
		        }
		    }
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
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends