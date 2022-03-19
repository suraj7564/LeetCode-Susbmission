class FreqStack {
public:
    map<int, vector<int>> m1;
    unordered_map<int, int> m2;
    FreqStack() {
        
    }
    
    void push(int x) {
        m2[x]++;
        m1[m2[x]].push_back(x);
    }
    
    int pop() {
        auto iter = m1.rbegin();
        int ret = iter->second[(iter->second).size()-1];
        iter->second.pop_back();
        m2[ret]--;
        if(iter->second.size()==0)m1.erase(iter->first);
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */