class Solution {
public:
    vector<int> find(int n){
        vector<int> v(10,0);
        while(n){
            v[n%10]++;
            n=n/10;
        }
        return v;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> v=find(n);
        int x=1;
        for(int i=0;i<31;i++){
            if(v==find(x)){
                return true;
            }
            x=x<<1;
        }
        return false;
    }
};