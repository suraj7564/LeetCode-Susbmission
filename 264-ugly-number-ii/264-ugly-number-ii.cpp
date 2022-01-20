class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[n+1];
        arr[0]=1;
        int x=2,y=3,z=5;
        int ii=1,j=1,k=1;
        for(int i=1;i<n;i++){
            int nxt=min({x,y,z});
            arr[i]=nxt;
            
            if(x==nxt){
                x=arr[ii]*2; // 1 2 3 4 5
                ii++;
            }
            if(y==nxt){
                y=arr[j]*3;
                j++;
            }
            if(z==nxt){
                z=arr[k]*5;
                k++;
            }
        }
        return arr[n-1];
    }
};