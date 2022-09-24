class Solution {
public:
    double f(string S) {
        auto i = S.find("(");
        if (i != string::npos) {
            string base = S.substr(0, i);
            string rep = S.substr(i + 1, S.length() - i - 2);
            for (int j = 0; j < 20; ++j) base += rep;
            return stod(base);
        }
        return stod(S);
    }
    bool isRationalEqual(string s, string t) {
        return f(s) == f(t);
    }
};