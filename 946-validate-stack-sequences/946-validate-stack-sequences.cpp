class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s1;
        int j=0;
        for(int i=0;i<pushed.size();i++){
            while(!s1.empty()&&s1.top()==popped[j]){
                s1.pop();
                j++;
            }
            s1.push(pushed[i]);
        }
        while(!s1.empty()&&s1.top()==popped[j]){
                s1.pop();
                j++;
            }
        if(s1.size()==0) return true;
        return false;
    }
};