//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void get(string &cur, vector<string>& ans, vector<int>& vis, string &s){
        if(cur.length() == s.length()){
            ans.push_back(cur);
            return;
        }
        
        for(int i=0;i<s.length();i++){
            if(vis[i] == 0){
                vis[i] = 1;
                cur.push_back(s[i]);
                get(cur, ans, vis, s);
                cur.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<string> permutation(string s)
    {
        //Your code here
        sort(s.begin(), s.end());
        int n = s.length();
        vector<int> vis(n, 0);
        vector<string> ans;
        string cur = "";
        get(cur, ans, vis, s);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends