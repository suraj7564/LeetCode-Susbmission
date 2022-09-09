class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        int n=pro.size();
        stack<vector<int> > s1;
        sort(pro.begin(),pro.end(),[&](vector<int>&a,vector<int>& b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]>b[0];
        });
        int cnt=0;
        s1.push(pro[0]);
        for(int i=1;i<n;i++){
            auto t=s1.top();
            while(!s1.empty()&&t[0]<pro[i][0]||t[1]<pro[i][1]){
                s1.pop();
                if(s1.empty()) break;
                t=s1.top();
            }
            if(!s1.empty()&&t[0]>pro[i][0]&&t[1]>pro[i][1]) cnt++;
            if(s1.empty())
            s1.push(pro[i]);
        }
        return cnt;
    }
};