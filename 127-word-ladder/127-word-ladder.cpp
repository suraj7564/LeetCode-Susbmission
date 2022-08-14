class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> m;
        for(auto x:wordList){
            m[x] = 1;
        }
        m[beginWord] = 1;
        for(auto x:m){
            string s = x.first;
            for(int i=0;i<s.length();i++)
            for(int j=0;j<26;j++){
                char ch = (char)(j+'a');
                string ss = s.substr(0,i);
                ss += ch;
                ss += s.substr(i+1);
                if(ch!=s[i] && m.find(ss)!=m.end()){
                    adj[s].push_back(ss);
                }
            }
        }
        queue<string> q;
        q.push(beginWord);
        map<string, int> vis;
        int cnt=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz-->0){
                string t=q.front();
                q.pop();
                if(t==endWord){
                    return cnt;
                }
                for(auto x:adj[t]){
                    if(!vis[x]){
                        q.push(x);
                        vis[x] = 1;
                    }
                }
            }
            cnt++;
        }
        return 0;
    }
};