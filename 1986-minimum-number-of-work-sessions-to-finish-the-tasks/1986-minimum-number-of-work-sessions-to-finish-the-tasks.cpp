class Solution {
public:
    int solve(vector<int>& tasks, int s){
        int c = 1,x = 0;
        for(auto y:tasks){
            if(x+y<=s){
                x+=y;
            }else{
                c++;
                x = y;
            }
        }
        return c;
    }
    int minSessions(vector<int>& tasks, int s) {
        int c = INT_MAX;
        int n = tasks.size();
        for(int i=0;i<5000;i++){
            random_shuffle(tasks.begin(),tasks.end());
            c = min(c,solve(tasks,s));
        }
        return c;
    }
};