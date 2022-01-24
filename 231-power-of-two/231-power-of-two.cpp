class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==-2147483648){
            return false;
        }
        if(n!=0 && !(n&(n-1))){
            return true;
        }
        return false;
    }
};