#include<bits/stdc++.h>
class MyCalendar {
public:
    set<pair<int,int>> books;
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        auto next = books.lower_bound({s, e}); // first element with key not go before k (i.e., either it is equivalent or goes after).
        if (next != books.end() && next->first < e) return false; // a existing book started within the new book (next)
        if (next != books.begin() && s < (--next)->second) return false; // new book started within a existing book (prev)
        books.insert({ s, e });
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */