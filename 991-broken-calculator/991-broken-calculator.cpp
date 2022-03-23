class Solution {
public:
    int brokenCalc(int x, int y) {
        int cnt=0;
        while(y>x){
            if(y%2) y++;
            else y=y/2;
            cnt++;
        }
        return cnt+x-y;
    }
};