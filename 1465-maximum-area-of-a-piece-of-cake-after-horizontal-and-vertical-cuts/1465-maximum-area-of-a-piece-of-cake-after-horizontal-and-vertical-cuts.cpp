class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int a=0;
        a=max(a,horizontalCuts[0]);
        for(int i=1;i<horizontalCuts.size();i++){
            a=max(a,(horizontalCuts[i]-horizontalCuts[i-1]));
        }
        a=max(a,(h-horizontalCuts[horizontalCuts.size()-1]));
        int b=0;
        b=max(b,verticalCuts[0]);
        for(int i=1;i<verticalCuts.size();i++){
            b=max(b,(verticalCuts[i]-verticalCuts[i-1]));
        }
        //cout<<h<<endl;
        b=max(b,(w-verticalCuts[verticalCuts.size()-1]));
        //cout<<a<<" "<<b<<endl;
        long long ans=((long long)a%1000000007*(long long)b%1000000007*1LL)%1000000007;
        return (int)ans;
        
    }
};