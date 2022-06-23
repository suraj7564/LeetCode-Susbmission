class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[&](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        int cnt = 0;
        int cur = 0;
        priority_queue<int> pq;
        int n = courses.size();
        for(int i=0;i<n;i++){
            if(courses[i][0]>courses[i][1]) continue;
            if(cur+courses[i][0]<=courses[i][1]){
                cur = cur+courses[i][0];
                pq.push(courses[i][0]);
                cnt++;
            }
            else{
                if(!pq.empty()&&pq.top()>courses[i][0]){
                    cur -= pq.top();
                    pq.pop();
                    cur += courses[i][0];
                    pq.push(courses[i][0]);
                }
            }
        }
        //cout<<endl;
        return cnt;
    }
};