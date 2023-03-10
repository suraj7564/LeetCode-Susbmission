//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        vector<int> cnt(26, 0);
        int i = 0, ans = 0;
        for(int j=0;j<S.length();j++){
            cnt[S[j] - 'a']++;
            for(int k=0;k<26;k++){
                while(cnt[k] > 1){
                    cnt[S[i] - 'a']--;
                    i++;
                }
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends