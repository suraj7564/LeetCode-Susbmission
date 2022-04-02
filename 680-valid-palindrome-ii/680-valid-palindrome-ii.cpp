class Solution {
public:
    bool validPalindrome(string s) {
        const int n = s.length();
        return validPalindromeHelper(s, 0, n - 1, true);
    }
private:
    bool validPalindromeHelper(string s, int l, int r, bool canDelete) {
        const int n = s.length();
        while(l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else if (canDelete) {
                return (
                    validPalindromeHelper(s, l + 1, r, false) || 
                    validPalindromeHelper(s, l, r - 1, false)
                );
            } else {
                return false;
            }
        }
        return true;
    }
};