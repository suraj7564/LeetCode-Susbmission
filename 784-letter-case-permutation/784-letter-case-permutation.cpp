class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n=s.length();
        for(int i=0;i<s.length();i++){
            if(s[i]>='A'&&s[i]<='Z'){
                s[i]=tolower(s[i]);
            }
        }
        vector<string> v;
        set<string> s1;
        int t=(1<<n);
        //cout<<t<<endl;
        for(int i=0;i<t;i++){
            string p=s;
            for(int j=0;j<n;j++){
                if((i&(1<<j))&&p[j]>='a'&&p[j]<='z'){
                    p[j]=toupper(p[j]);
                }
            }
            s1.insert(p);
        }
        for(auto x:s1){
            v.push_back(x);
        }
        return v;
    }
};