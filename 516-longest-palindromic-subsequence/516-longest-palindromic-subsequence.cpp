class Solution {
public:
    int find(string s,string s1){
        int n=s1.size();
        vector<int> preRow(n+1,0);
        for(int i=1;i<=n;i++){
            vector<int> curRow(n+1,0);
            for(int j=1;j<=n;j++){
                if(s[i-1]==s1[j-1]){
                    curRow[j]=preRow[j-1]+1;
                }
                else{
                    curRow[j]=max(preRow[j],curRow[j-1]);
                }
            }
            preRow=curRow;
        }
        return preRow[n];
    }
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        return find(s,s1);
    }
};