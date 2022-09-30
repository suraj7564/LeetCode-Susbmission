class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<vector<int>> res;
        vector<vector<int>> cur;
        for(auto x:b){
            int s = x[0], e = x[1], h = x[2];
            cur.push_back({s, -h});
            cur.push_back({e, h});
        }
        sort(cur.begin(), cur.end());
        multiset<int> s1;
        s1.insert(0);
        int curH = 0;
        for(int i=0;i<cur.size();i++){
            int h = cur[i][1];
            if(h>0){
                s1.erase(s1.find(-h));
            }
            else s1.insert(h);
            if(curH != *s1.begin()){
                res.push_back({cur[i][0], *s1.begin()*-1});
                curH = *s1.begin();
            }
        }
        return res;
    }
};