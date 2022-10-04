class Solution {
public:
    class DSU{
        public:
        vector<int> p;
        DSU(){
            for(int i=0;i<=100000;i++){
                p.push_back(i);
            }
        }
        int find(int x){
            if(p[x] == x){
                return x;
            }
            return p[x] = find(p[x]);
        }
        bool join(int x, int y){
            x = find(x);
            y = find(y);
            if(x != y){
                p[x] = y;
                return true;
            }
            return false;
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU d1, d2;
        int cnt = 0;
        for(auto x:edges){
            if(x[0] == 3){
                if(!d1.join(x[1], x[2])) cnt++;
                d2.join(x[1], x[2]);
            }
        }
        for(auto x:edges){
            if(x[0] == 1){
                if(!d1.join(x[1], x[2])) cnt++;
            }
        }
        for(auto x:edges){
            if(x[0] == 2){
                if(!d2.join(x[1], x[2])) cnt++;
            }
        }
        for(int i=1;i<=n;i++){
            if(d1.find(1) != d1.find(i) || d2.find(1) != d2.find(i)) return -1;
        }
        return cnt;
    }
};