class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int> > s1;
        for(int i=0;i<s.length();i++){
            if(s1.empty()){
                s1.push({s[i],1});
            }
            else if(s[i]==s1.top().first){
                s1.top().second++;
            }
            else{
                s1.push({s[i],1});
            }
            if(s1.top().second==k){
                s1.pop();
            }
        }
        string ans="";
        while(!s1.empty()){
            int r=s1.top().second;
            while(r-->0)
            ans+=s1.top().first;
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};