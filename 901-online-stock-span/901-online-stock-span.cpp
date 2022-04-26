class StockSpanner {
public:
    vector<int> v;
    stack<int> s1;
    int idx = 0;
    StockSpanner() {
        idx = 0;
    }
    
    int next(int price) {
        int ans = 1;
        while(!s1.empty()&&v[s1.top()]<=price){
            s1.pop();
        }
        if(!s1.empty()){
            ans = idx-s1.top();
        }
        else ans = idx+1;
        v.push_back(price);
        s1.push(idx);
        idx++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */