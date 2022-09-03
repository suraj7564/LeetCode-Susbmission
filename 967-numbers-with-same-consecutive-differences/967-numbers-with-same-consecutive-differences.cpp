class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        unordered_map<int, int> m;
        for(int i=1;i<=9;i++){
            q.push(i);
            m[i] = i;
        }
        vector<int> ans;
        long long limit = pow(10, n);
        while(!q.empty()){
            long long t = q.front();
            q.pop();
            if(t*10LL>=limit){
                ans.push_back(t);
                continue;
            }
            int x = t%10;
            int x1 = x-k;
            int x2 = x+k;
            if(x1>=0){
                int num = t*10+x1;
                if(m[num] == 0){
                    q.push(num);
                    m[num] = 1;
                }
            }
            if(x2<10){
                int num = t*10+x2;
                if(m[num] == 0){
                    q.push(num);
                    m[num] = 1;
                }
            }
        }
        return ans;
    }
};