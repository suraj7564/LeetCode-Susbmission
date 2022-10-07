class MyCalendarTwo {
public:
    vector<pair<int, int>> a;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        vector<pair<int, int>> b = a;
        b.push_back({start, -1});
        b.push_back({end-1, 1});
        sort(b.begin(), b.end());
        int cnt = 0;
        for(int i=0;i<b.size();i++){
            if(b[i].second == -1) cnt++;
            else cnt--;
            if(cnt > 2) return false;
        }
        a.push_back({start, -1});
        a.push_back({end-1, 1});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */