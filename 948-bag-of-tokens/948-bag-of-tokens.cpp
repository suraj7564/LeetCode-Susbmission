class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size()-1, ans = 0, cur = 0; 
        while(i<=j){
            if(power>=tokens[i]){
                cur++;
                power -= tokens[i];
                i++;
            }
            else{
                cur--;
                if(cur<0) break;
                power += tokens[j];
                j--;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};