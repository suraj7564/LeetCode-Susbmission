class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> ans;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="+"){
                stack<int> s1;
                int sum=0;
                int t=2;
                while(t-->0){
                    int x;
                    x=ans.top();
                    ans.pop();
                    sum+=x;
                    s1.push(x);   
                }
                while(s1.size()!=0){
                    int x=s1.top();
                    s1.pop();
                    ans.push(x);
                }
                ans.push(sum);
                
            }
            else if(ops[i]=="C"){
                ans.pop();
            }
            else if(ops[i]=="D"){
                int x=ans.top();
                ans.push(2*x);
            }
            else{
                ans.push(stoi(ops[i]));
            }
        }
        int sum=0;
         while(ans.size()!=0){
                    int x;
                    x=ans.top();
                    ans.pop();
                    sum+=x;  
                }
        return sum;
    }
};