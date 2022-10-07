class MyCalendarThree {
public:
    vector<pair<int, int>> a;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        a.push_back({start, -1});
        a.push_back({end-1, 1});
        sort(a.begin(), a.end());
        int cnt = 0, mx = 0;
        for(int i=0;i<a.size();i++){
            if(a[i].second == -1) cnt++;
            else cnt--;
            mx = max(mx, cnt);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */