class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0)return {};
        vector<string> res;
        vector <string> val = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;
        queue<string>q;q.push("");
        while(!q.empty()){
                string temp=q.front();
                q.pop();
                int ch=temp.size();
                int j=digits[ch]-'0';
                for(int k=0;k<val[j].size();k++){
                    string tt=temp+val[j][k];
                    if(tt.size()==n)res.push_back(tt);
                    else q.push(tt);
                }
        }
        return res;
    }
};