class Solution {
public:
    int twoEggDrop(int n) {
        return ceil((-1+sqrt(8*n+1))/2.0);
    }
};