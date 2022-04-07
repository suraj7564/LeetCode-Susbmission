class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            vector<int> v;
            v.clear();
            sort(stones.begin(),stones.end());
            int n=stones.size();
            if(stones[n-1]==stones[n-2]){
                for(int i=0;i<n-2;i++){
                    v.push_back(stones[i]);
                }
            }
            else{
                for(int i=0;i<n-2;i++){
                    v.push_back(stones[i]);
                }
                v.push_back(stones[n-1]-stones[n-2]);
            }
            stones.clear();
            stones=v;
        }
        if(stones.size()==1){
            return stones[0];
        }
        return 0;
    }
};