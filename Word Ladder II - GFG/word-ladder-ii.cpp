//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st{wordList.begin(),wordList.end()};
        st.erase(beginWord);
        
        queue<vector<string>>q;
        q.push({beginWord});
        
        vector<vector<string>>ans;
        vector<string>usedOnLevel;
        
        int level = 0;
        
        while(!q.empty()) {
            vector<string>v = q.front();
            q.pop();
            
            if(v.size() > level){
                level++;
                for(auto it: usedOnLevel)
                    st.erase(it);
            }
            
            string word = v.back();
            
            if(word == endWord) {
                if(ans.size() == 0 or ans[0].size() == v.size())
                    ans.push_back(v);
            }
            
            for(int i = 0;i<word.size();i++) {
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++) {
                    word[i] = ch;
                    if(st.count(word)) {
                        v.push_back(word);
                        q.push(v);
                        usedOnLevel.push_back(word);
                        v.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends