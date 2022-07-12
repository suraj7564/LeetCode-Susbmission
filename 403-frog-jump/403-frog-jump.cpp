class Solution {
public:
    map<int,int> m;
    map<pair<int,int>,int> m1;
    bool b;
    void find(int idx,int curJump,vector<int>& stones){
        if(idx==stones.size()-1){
            b = true;
            return;
        }
        if(m1.find({idx,curJump})!=m1.end()) return;
        m1[{idx,curJump}] = 1;
        for(int i=-1;i<=1;i++){
            int pos = stones[idx]+curJump+i;
            if(m.find(pos)!=m.end()){
                find(m[pos],curJump+i,stones);
            }
        }
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        for(int i=0;i<stones.size();i++){
            m[stones[i]] = i;
        }
        b = false; 
        find(1, 1, stones);
        return b;
    }
};