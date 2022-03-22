class Solution {
public:
    string getSmallestString(int n, int k) {
        int a[n];
        for(int i=0;i<n;i++){
            a[i]=1;
        }
        k=k-n;
        int i=n-1;
        while(k>0 && i>=0){
            if(k>=25){
                a[i]+=25;
                k=k-25;
                i--;
            }
            else{
                a[i]+=k;
                k=0;
                i--;
            }
        }
        string s="";
        for(int i=0;i<n;i++){
            s+=char(96+a[i]);
            //cout<<a[i]<<" ";
        }
        //cout<<endl;
        return s;
    }
};