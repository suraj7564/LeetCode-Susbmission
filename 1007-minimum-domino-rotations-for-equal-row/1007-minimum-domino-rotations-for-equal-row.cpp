class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> v(7,0),v1(7,0),v2(7,0);
        for(int i=0;i<A.size();i++){
            if(A[i]==B[i]){
                v[A[i]]++;
            }
            else{
                v1[A[i]]++;
                v2[B[i]]++;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<7;i++){
            if(v[i]+v1[i]+v2[i]==A.size()){
                ans=min({ans,v1[i],v2[i]});
            }
        }
        if(ans==INT_MAX) return -1;
        
        return ans;
    }
};