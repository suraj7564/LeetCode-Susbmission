//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    //aabaabaa
        //aaba
        //aaba abaa
        //a abaa baa
        //aa baab aa
        //aab aaba a
        //aaba abaa
	    vector<int> cnt(26, 0);
	    for(auto x:pat){
	        cnt[x - 'a']++;
	    }
	    vector<int> cur(26, 0);
	    for(int j=0;j<pat.size();j++){
	        cur[txt[j] - 'a']++;
	    }
	    int ans = 0;
	    
	    if(cnt == cur){
	        ans++;
	    }
	  
	    for(int j=pat.size();j<txt.size();j++){
	        cur[txt[j] - 'a']++;
	        cur[txt[j - pat.size()] - 'a']--;
	        if(cur == cnt){
	            ans++;
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends