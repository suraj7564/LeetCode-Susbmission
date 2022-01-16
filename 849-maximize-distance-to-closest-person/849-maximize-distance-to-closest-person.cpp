class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int> v(n,0),v1(n,0),v2(n,0);
        int x=INT_MAX;
        bool b=false;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                x=0;
                b=true;
            }else if(b) x++;
            v[i]=x;
        }
        x=INT_MAX;
        b=false;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1){
                x=0;
                b=true;
            }else if(b)x++;
            v1[i]=x;
        }
        for(int i=0;i<n;i++){
            v2[i]=min(v[i],v1[i]);
        }
        return *max_element(v2.begin(),v2.end());
    }
};