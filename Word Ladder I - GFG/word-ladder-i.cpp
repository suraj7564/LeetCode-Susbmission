//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        map<string, vector<string>> adj;
        wordList.push_back(startWord);
        //wordList.push_back(targetWord);
        for(int i=0;i<wordList.size();i++){
            for(int j=i + 1;j<wordList.size();j++){
                if(wordList[i].length() != wordList[j].length()) continue;
                int cnt = 0;
                for(int k=0;k<wordList[i].length();k++){
                    cnt += wordList[i][k] != wordList[j][k];
                }
                if(cnt == 1){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        int lvl = 1;
        queue<string> q;
        q.push(startWord);
        unordered_map<string, int> mark;
        mark[startWord] = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz-->0){
                auto t = q.front();
                q.pop();
                if(t == targetWord) return lvl;
                for(auto x:adj[t]){
                    if(mark.find(x) == mark.end()){
                        mark[x] = 1;
                        q.push(x);
                    }
                }
            }
            lvl++;
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends