class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        int n=wordList.size();
        vector<bool> vis(n,false);
        int cnt=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz-->0){
                string t=q.front();
                q.pop();
                if(t==endWord){
                    return cnt;
                }
                for(int i=0;i<n;i++){
                    if(vis[i]) continue;
                    int c=0;
                    string cur=wordList[i];
                    for(int j=0;j<cur.length();j++){
                        if(cur[j]!=t[j]){
                            c++;
                        }
                    }
                    if(c==1){
                        vis[i]=true;
                        q.push(cur);
                    }
                }
            }
            cnt++;
        }
        return 0;
    }
};