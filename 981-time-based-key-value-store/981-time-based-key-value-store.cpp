class TimeMap {
public:
    map<pair<string, int>, string> m;
    map<string, set<int>> m1;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[{key, timestamp}] = value;
        m1[key].insert(timestamp);
    }
    
    string get(string key, int timestamp) {
        auto it = m1[key].lower_bound(timestamp);
        if(*it != timestamp){
            if(it == m1[key].begin()) return "";
            it--;
            return m[{key, *it}];
        }
        return m[{key, timestamp}];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */