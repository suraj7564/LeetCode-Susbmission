class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s1;
        int n=heights.size();
        s1.push(0);
        int ans=0;
        for(int i=0;i<n;i++){
            while(!s1.empty()&&heights[s1.top()]>heights[i]){
                int t=s1.top();
                s1.pop();
                if(s1.empty())
                    ans=max(ans,heights[t]*i);
                else{
                    ans=max(ans,heights[t]*(i-s1.top()-1)); 
                }
                
            }
            s1.push(i);
        }
        while(!s1.empty()){
            int t=s1.top();
                s1.pop();
                if(s1.empty())
                    ans=max(ans,heights[t]*n);
                else{
                    ans=max(ans,heights[t]*(n-s1.top()-1)); 
                }
        }
        return ans;
    }
};