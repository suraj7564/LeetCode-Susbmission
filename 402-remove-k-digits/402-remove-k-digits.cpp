class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        s.push(num[0]);
        for(int i=1;i<num.length();i++){
            while(!s.empty()&&s.top()>num[i]&&k>0){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k>0){
            s.pop();
            k--;
        }
        string ans="";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        for(i=0;i<ans.length();i++){
            if(ans[i]!='0'){
                break;
            }
        }
        string s1=ans.substr(i);
       // cout<<ans<<" "<<s1<<endl;
        if(s1.length()==0) return "0";
        return s1;
    }
};