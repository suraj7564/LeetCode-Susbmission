class Solution {
public:
    bool canEat(vector<int> v,int h,int k){
        int r=0;
        for(auto x:v){
            if(x%k){
                r++;
            }
            r+=x/k;
        }
        return r<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=1;
        for(auto x:piles){
            mx=max(mx,x);
        }
        int x=1;
        int y=mx;
        int res=-1;
        while(x<=y){
            int mid=(x+y)/2;
            if(canEat(piles,h,mid)){
                res=mid;
                y=mid-1;
            }
            else x=mid+1;
        }
        return res;
    }
};