class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0) return 0;
        int cnt=0;
        while(num){
            if(num%2){
                num--;
                cnt++;
            }
            num=num/2;
            cnt++;
        }
        return cnt-1;
    }
};