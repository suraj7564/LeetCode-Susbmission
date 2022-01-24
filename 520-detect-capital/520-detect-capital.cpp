class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0,cnt1=0;
        bool b=false;
        if(word[0]>='A' and word[0]<='Z' ){
            b=true;
            cnt++;
        }
        else{
            cnt1++;
        }
        for(int i=1;i<word.length();i++){
            if(word[i]>='A' and word[i]<='Z' ){
                cnt++;
            }
            else{
                cnt1++;
            }
        }
        if((b and cnt==1) || cnt==word.length() || cnt1==word.length()){
            return true;
        }
        return false;
    }
};