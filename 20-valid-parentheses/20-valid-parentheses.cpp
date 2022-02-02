class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(auto x:s){
            if(x=='('||x=='['||x=='{'){
                s1.push(x);
            }
            else if(!s1.empty()){
                char ch=s1.top();
                if(x==']'&&ch=='['||x=='}'&&ch=='{'||x==')'&&ch=='('){
                    s1.pop();
                }
                else return false;
            }
            else return false;
        }
        return s1.empty();
    }
};