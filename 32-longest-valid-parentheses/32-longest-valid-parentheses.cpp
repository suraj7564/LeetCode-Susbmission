class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>> s1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                s1.push({s[i],i});
            }
            else{
                if(!s1.empty()){
                    if(s1.top().first=='('){
                        s1.pop();
                    }
                    else{
                        s1.push({s[i],i});
                    }
                }
                else{
                    s1.push({s[i],i});
                }
            }
        }
        int cur=s.length();
        int mx=0;
        while(!s1.empty()){
            mx=max(mx,cur-s1.top().second-1);
            cur=s1.top().second;
            s1.pop();
        }
        mx=max(mx,cur);
        return mx;
    }
};