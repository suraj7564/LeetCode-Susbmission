class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string s1="";
        int x=0,y=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                s1+=s[i];
                x++;
            }
            else if(s[i]==')'){
                if(x>0){
                    s1+=s[i];
                    x--;
                }
            }
            else{
                s1+=s[i];
            }
        }
        string ans=""; 
        bool b=true;
        for(int i=s1.length()-1;i>=0;i--){
            if(s1[i]=='(' && b){
                x--;
            }
            else{
                ans+=s1[i];
            }
            if(x==0){
                b=false;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};