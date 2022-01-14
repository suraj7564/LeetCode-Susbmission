class Solution {
public:
    int myAtoi(string s) {
        long res = 0;
        bool is_neg = false;
        int i;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            
            if (s[i] == '-' || s[i] == '+') {
                is_neg = s[i] == '-' ;
                i++;
                break;
            } else if (!isdigit(s[i])) { 
                return 0;
            } else {
                break;
            }
        }
  
        while (i < s.size() && isdigit(s[i])) {
            res = res * 10 + s[i] - '0';
            if (is_neg && -res < numeric_limits<int>::min()) {
                return numeric_limits<int>::min();
            } else if (!is_neg && res > numeric_limits<int>::max()) {
                return numeric_limits<int>::max();
            }
            i++;
        }
        int val = res;
        if (is_neg) {
            val = -res;
        }
        
        return val;
    }
};