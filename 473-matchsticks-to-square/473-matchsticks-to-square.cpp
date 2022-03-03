class Solution {
public:
    bool solve(vector<int>& m, int idx, vector<int> &s){
          if(idx == m.size()){
               if(s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0) return true;
               return false;
          }
        
          for(int i =0; i<4; i++){
              if(m[idx] > s[i]) continue;
              s[i] -= m[idx];
              if(solve(m, idx + 1, s)) return true;
              s[i] += m[idx];
          }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(auto x:matchsticks){
            sum+=x;
        }
        if(sum%4){
            return false;
        }
        sum/=4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sides(4,sum);
        return solve(matchsticks, 0, sides);
    }
};