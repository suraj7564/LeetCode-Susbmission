class Solution {
public:
    int countSubstrings(string s) {
        vector<string> v;
        for(int i=0;i<s.length();i++){
            string s1="";
            for(int j=i;j<s.length();j++){
                s1+=s[j];
                v.push_back(s1);
            }
        }
        int cnt=0;
        for(int i=0;i<v.size();i++){
            string s2=v[i];
            reverse(s2.begin(),s2.end());
            //cout<<s2<<" "<<v[i]<<endl;
            if(s2==v[i]) cnt++;
        }
        return cnt;
    }
};