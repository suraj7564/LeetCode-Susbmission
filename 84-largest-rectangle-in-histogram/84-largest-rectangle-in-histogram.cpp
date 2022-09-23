class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans = 0;
         stack<int> s1;
        // s1.push(0);
         int n = h.size();
         for(int i=0;i<n;i++){
             while(!s1.empty()&&h[s1.top()]>h[i]){
                 int cur = s1.top();
                 s1.pop();
                 if(s1.empty()){
                     ans = max(ans,h[cur]*i);
                 }
                 else{
                     ans = max(ans,h[cur]*(i-s1.top()-1));
                 }
             }
             s1.push(i);
         }
         while(!s1.empty()){
            int cur = s1.top();
            s1.pop();
            if(s1.empty()){
                ans = max(ans,h[cur]*n);
            }
            else{
                ans = max(ans,h[cur]*(n-s1.top()-1));
            }
        }
        return ans;
    }
};