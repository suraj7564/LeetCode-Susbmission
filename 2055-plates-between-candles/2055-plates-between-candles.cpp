class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> pre(n+1,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                cnt++;
            }
            pre[i+1] = cnt;
        }
        vector<int> left(n+1,-1);
        vector<int> right(n+1,-1);
        int l = -1, r = -1;
        for(int i=0;i<n;i++){
            if(s[i]=='|'){
                l = i+1;
            }
            if(s[n-i-1]=='|'){
                r = n-i;
            }
            left[i+1] = l;
            right[n-i] = r;
        }
    
        vector<int> ans;
        for(auto x:queries){
            int l = x[0]+1, r = x[1]+1;
            if(left[r]==-1||right[l]==-1){
                ans.push_back(0);
                continue;
            }
            //cout<<left[r]<<" "<<right[l]<<endl;
            ans.push_back(max(0,pre[left[r]]-pre[right[l]]));
        }
        return ans;
    }
};