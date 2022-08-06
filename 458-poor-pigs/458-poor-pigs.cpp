class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets==1) return 0;
        int test = minutesToTest/minutesToDie;
        int canTest = test+1;
        int cnt = 0;
        int cur = 1;
        while(cur<buckets){
            cur*=canTest;
            cnt++;
        }
        return cnt;
    }
};